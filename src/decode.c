#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
  FILE* input;

  int i, j, max, tmp, lit;
  max = 0;
  int on[730];
  for (i = 0; i <= 729; i++) {
    on[i] = 0; }

  input = stdin;
  if (argc > 1)
    input = fopen (argv[1], "r");

  tmp = 0;
  while (tmp != EOF) {
    tmp = fscanf (input, " %i ", &lit);
    if ((lit > 0) && (lit < 730)) {
      on[ lit ] = 1;
      if (lit > max) max = lit;
    }
  }

  int size = ((max-1) / 27) + 1;
  for (i = 0; i < size; i++) {
    int first;
    first = 1;
    for (j = 0; j < 9; j++) {
      if (on[i*27 + j + 1]) {
        if (first) { printf ("("); first = 0; }
        else       { printf (" + "); }
        printf ("a");
        printf ("%i%i", (j/3) + 1, (j%3) + 1); } }
    printf(")*");

    first = 1;
    for (j = 0; j < 9; j++) {
      if (on[i*27 + j + 10]) {
        if (first) { printf ("("); first = 0; }
        else       { printf (" + "); }
        printf ("b");
        printf ("%i%i", (j/3) + 1, (j%3) + 1); } }
    printf(")*");

    first = 1;
    for (j = 0; j < 9; j++) {
      if (on[i*27 + j + 19]) {
        if (first) { printf ("("); first = 0; }
        else       { printf (" + "); }
        printf ("c");
        printf ("%i%i", (j/3) + 1, (j%3) + 1); } }
    printf(")\n");
  }
}
