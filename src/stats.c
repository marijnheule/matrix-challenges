#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
  FILE *exp;

  int i, tmp;
  char c;
  int on[27];
  int line = 0;
  int sum = 0;

  exp = fopen (argv[1], "r");


  for (i = 0; i < 27; i++) on[i] = 0;
  while (1) {
    tmp = fscanf (exp, "%c", &c);
    if (tmp == EOF) break;
    if (c == '(') continue;
    if (c == ')') continue;
    if (c == ' ') continue;
    if (c == '+') continue;
    if (c == '*') continue;

    if (c == '\n') {
      int count = 0;
      if (on[ 0] && on[ 9] && on[18]) count++;
      if (on[ 0] && on[10] && on[21]) count++;
      if (on[ 0] && on[11] && on[24]) count++;

      if (on[ 1] && on[12] && on[18]) count++;
      if (on[ 1] && on[13] && on[21]) count++;
      if (on[ 1] && on[14] && on[24]) count++;

      if (on[ 2] && on[15] && on[18]) count++;
      if (on[ 2] && on[16] && on[21]) count++;
      if (on[ 2] && on[17] && on[24]) count++;

      if (on[ 3] && on[ 9] && on[19]) count++;
      if (on[ 3] && on[10] && on[22]) count++;
      if (on[ 3] && on[11] && on[25]) count++;

      if (on[ 4] && on[12] && on[19]) count++;
      if (on[ 4] && on[13] && on[22]) count++;
      if (on[ 4] && on[14] && on[25]) count++;

      if (on[ 5] && on[15] && on[19]) count++;
      if (on[ 5] && on[16] && on[22]) count++;
      if (on[ 5] && on[17] && on[25]) count++;

      if (on[ 6] && on[ 9] && on[20]) count++;
      if (on[ 6] && on[10] && on[23]) count++;
      if (on[ 6] && on[11] && on[26]) count++;

      if (on[ 7] && on[12] && on[20]) count++;
      if (on[ 7] && on[13] && on[23]) count++;
      if (on[ 7] && on[14] && on[26]) count++;

      if (on[ 8] && on[15] && on[20]) count++;
      if (on[ 8] && on[16] && on[23]) count++;
      if (on[ 8] && on[17] && on[26]) count++;

      printf ("%i\n", count);

      for (i = 0; i < 27; i++) {
        on[i] = 0; }
      line++;
      continue; }

    int sum = 0;
    if (c == 'b') sum = 9;
    if (c == 'c') sum = 18;

    tmp = fscanf (exp, "%c", &c);
    if (c == '2') sum += 3;
    if (c == '3') sum += 6;

    tmp = fscanf (exp, "%c", &c);
    if (c == '2') sum += 1;
    if (c == '3') sum += 2;

    on[sum] = 1;
  }
}
