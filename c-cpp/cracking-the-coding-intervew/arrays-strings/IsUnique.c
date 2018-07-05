#include <stdio.h>
#include <stdbool.h>

/*
// Using 1 extra array for couting characters
bool IsUnique(char *A) {
  int count[26];
  int i;
  for (i = 0; i < 26; i++)
    count[i] = 0;
  while(*A != NULL) {
    printf("%c\n", *A);
    count[*A - 'a'] += 1;
    if (count[*A - 'a'] > 1) {
      return false;
    }
    A++;
  }

  return true;
}
*/

// Dont use additional array
// Assumming that the input string contains only lower-case ascii characters (a->z)
bool IsUnique(char *A) {
  int mask,c;
  mask = 0;
  while (*A != NULL) {
    c = *A - 'a';
    A++;
    if ((mask & (1 << c)) > 0)
      return false;
    mask |= 1 << c;
  }
  return true;
}
