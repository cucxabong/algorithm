#include <stdio.h>

int main() {
  int N[] = {1, 2, 3, 4, 5, 6, 7};
  int *A = N;
  while (*N != NULL)
    printf("%d\n", *N++);

  return 0;
}
