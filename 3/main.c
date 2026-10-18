#include <stdio.h>
#include <string.h>

int main() {
  char str[1000];

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);
  
  str[strcspn(str, "\n")] = '\0';

  const int str_len = strlen(str);
  char reversed_str[str_len + 1];
  
  for (int i = str_len - 1, j = 0; i >= 0; i--, j++) {
    reversed_str[j] = str[i];
  }

  reversed_str[str_len] = '\0';

  printf("Reversed string: %s", reversed_str);

  return 0;
}
