#include <stdio.h>
#include <stdlib.h>

// Modify the input string in-place
// Scanning from start => end
/*
void URLify(char *A, int sz) {
  int i, c;
  i = 0;
  while (A[i] != NULL) {
    if (A[i] == ' ') {
      c = sz-1;
      while (c > i) {
        A[c+2] = A[c];
        c--;
      }
      sz += 2;
      A[i++] = '%';
      A[i++] = '2';
      A[i++] = '0';
    } else {
      i++;
    }
  }
}
*/

// Scanning from end => start
void URLify(char *A) {
  char *pos, *c;
  pos = A;

  // Finding the end position => pos
  // Finding the last character position => c;
  while (*pos != NULL) {
    if ('a' <= *pos && *pos <= 'z')
      c = pos;
    pos++;
  }
  pos--;

  // Scanning string from the end => start
  while (pos != A) {
    if (*c == ' ') {
      *pos-- = '0';
      *pos-- = '2';
      *pos-- = '%';
    } else {
      *pos-- = *c;
    }
    c--;
  }
}
