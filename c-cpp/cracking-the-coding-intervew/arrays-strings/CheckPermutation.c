#include <stdio.h>
#include <stdbool.h>

// We will assume that input string involve characters from ASCII table
// and characters are case-sensitive
// and space is the valid character
bool CheckPermutation(char *A, char *B) {
  int i, count[128];
  for (i = 0; i < 128; i++)
    count[i] = 0;
  while (*A != NULL) {
    count[*A]++;
    A++;
  }

  while (*B != NULL) {
    count[*B]--;
    if (count[*B] < 0)
      return false;
    B++;
  }

  for (i = 0; i < 128; i++)
    if (count[i] != 0)
      return false;
  return true;
}

