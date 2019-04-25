#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
  FILE *exp;

  int i, tmp;
  char c;
  int on[27];
  int line = 0;
  int sum = 0;


  exp = stdin;

  if (argc > 1) {
    exp = fopen (argv[1], "r"); }

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
      for (i = 0; i < 27; i++) {
        if (!on[i]) printf ("-");
        printf ("%i 0\n", line * 27 + i + 1);
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
