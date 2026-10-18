#include <stdio.h>
#include <math.h>

#define PI 3.14159265

float funcZ1(float alpha) {
  return cos(alpha) + sin(alpha) + cos(3 * alpha) + sin(3 * alpha);
}

float funcZ2(float alpha) {
  return 2 * sqrt(2) * cos(alpha) * sin(PI/4 + 2 * alpha);
}

int main() {
  float alpha, z1, z2;

  printf("alpha=");
  scanf("%f", &alpha);
  
  z1 = funcZ1(alpha);
  z2 = funcZ2(alpha);

  printf("z1 = %.2f, z2 = %.2f", z1, z2);

  return 0;
}
