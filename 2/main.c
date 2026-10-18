#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
  const char *title;
  float price; // pounds
  const char *author;
  const char *language;
  int release_year;
  int weight; // in grams
  int pages;
}Book;

typedef struct LibraryItem {
  Book *data;
  struct LibraryItem *next_item;
}LibraryItem;

typedef struct Library {
  LibraryItem *head;
}Library;

Book *create_book(const char *title, float price, const char *author, 
    const char *language, int release_year, int weight, int pages) {
  Book *book = malloc(sizeof *book);

  *book = (Book) {
    .title = title,
    .price = price,
    .author = author,
    .language = language,
    .release_year = release_year,
    .weight = weight,
    .pages = pages
  };

  return book;
}

Library *create_library() {
  Library *lib = malloc(sizeof *lib);
  
  *lib = (Library) {
    .head = NULL,
  };

  return lib;
}

void insert_book(Library *lib, Book *book) {
  LibraryItem *item = malloc(sizeof *item);

  item->data = book;
  item->next_item = NULL;

  if (lib->head == NULL) {
    lib->head = item;
    return;
  }

  LibraryItem *current = lib->head;
  
  while (current->next_item != NULL) {
    current = current->next_item;
  }

  current->next_item = item;
}

void print_library(Library *lib) {
  LibraryItem *item = lib->head; 
  
  int i = 1;

  while (item != NULL) {
    printf("Book #%d:\n", i);
    printf("  title = \"%s\"\n", item->data->title);
    printf("  price = £%.2f\n", item->data->price);
    printf("  author = \"%s\"\n", item->data->author);
    printf("  language = \"%s\"\n", item->data->language);
    printf("  release_year = %d\n", item->data->release_year);
    printf("  weight = %d\n", item->data->weight);
    printf("  pages = %d\n",item->data->pages);
    printf("\n");
    i++;
    item = item->next_item;
  }
}

void free_library(Library *lib) {
  LibraryItem *item = lib->head;

  while (item != NULL) {
    LibraryItem *next = item->next_item;
    free(item->data);
    free(item);

    item = next;
  }

  free(lib);
}

int main() {
  Library *lib = create_library();
  
  Book *book1 = create_book(
    "Harry Potter and the Philosopher's Stone",
    8.99,
    "J. K. Rowling",
    "English",
    1997,
    400,
    223
  );

  Book *book2 = create_book(
    "Harry Potter and the Chamber of Secrets",
    8.99,
    "J. K. Rowling",
    "English",
    1998,
    400,
    251
  );

  Book *book3 = create_book(
    "Harry Potter and the Prisoner of Azkaban",
    8.99,
    "J. K. Rowling",
    "English",
    1999,
    450,
    317
  );

  Book *book4 = create_book(
    "Harry Potter and the Goblet of Fire",
    9.99,
    "J. K. Rowling",
    "English",
    2000,
    800,
    636
  );

  Book *book5 = create_book(
    "Harry Potter and the Order of the Phoenix",
    9.99,
    "J. K. Rowling",
    "English",
    2003,
    1000,
    766
  );

  Book *book6 = create_book(
    "Harry Potter and the Half-Blood Prince",
    9.99,
    "J. K. Rowling",
    "English",
    2005,
    700,
    607
  );

  Book *book7 = create_book(
    "Harry Potter and the Deathly Hallows",
    9.99,
    "J. K. Rowling",
    "English",
    2007,
    800,
    607
  );

  insert_book(lib, book1);
  insert_book(lib, book2);
  insert_book(lib, book3);
  insert_book(lib, book4);
  insert_book(lib, book5);
  insert_book(lib, book6);
  insert_book(lib, book7);
  
  print_library(lib);
  free_library(lib);

  return 0;
}
