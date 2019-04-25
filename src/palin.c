#include <stdio.h>
#include <stdlib.h>

int sdim;

int getAvar (int i, int a) {
  return i * sdim * 3 + a + 1; }

int getBvar (int i, int b) {
  return i * sdim * 3 + b + 1 + sdim; }

int getCvar (int i, int c) {
  return i * sdim * 3 + c + 1 + 2 * sdim; }

int main (int argc, char ** argv) {
  int rows;
  int next;

  sdim = 9;

  rows = atoi (argv[1]);
  next = atoi (argv[2]);

  int i, j;

  for (i = 0; i < 2*next - 1; i+=2) {
    for (j = 0; j < sdim - 1; j++) {
       printf ("%i %i 0\n",  getAvar (i, j), -getBvar (i+1, 3*j % (sdim-1)));
       printf ("%i %i 0\n", -getAvar (i, j),  getBvar (i+1, 3*j % (sdim-1)));
       printf ("%i %i 0\n",  getBvar (i, j), -getAvar (i+1, 3*j % (sdim-1)));
       printf ("%i %i 0\n", -getBvar (i, j),  getAvar (i+1, 3*j % (sdim-1)));
       printf ("%i %i 0\n",  getCvar (i, j), -getCvar (i+1, 3*j % (sdim-1)));
       printf ("%i %i 0\n", -getCvar (i, j),  getCvar (i+1, 3*j % (sdim-1))); }
     printf   ("%i %i 0\n",  getAvar (i, j), -getBvar (i+1, j));
     printf   ("%i %i 0\n", -getAvar (i, j),  getBvar (i+1, j));
     printf   ("%i %i 0\n",  getBvar (i, j), -getAvar (i+1, j));
     printf   ("%i %i 0\n", -getBvar (i, j),  getAvar (i+1, j));
     printf   ("%i %i 0\n",  getCvar (i, j), -getCvar (i+1, j));
     printf   ("%i %i 0\n", -getCvar (i, j),  getCvar (i+1, j)); }

  for (i = 2*next; i < rows; i++) {
    for (j = 0; j < sdim - 1; j++) {
       printf ("%i %i 0\n",  getAvar (i, j), -getBvar (i, 3*j % (sdim-1)));
       printf ("%i %i 0\n", -getAvar (i, j),  getBvar (i, 3*j % (sdim-1)));
       printf ("%i %i 0\n",  getCvar (i, j), -getCvar (i, 3*j % (sdim-1))); }
     printf   ("%i %i 0\n",  getAvar (i, j), -getBvar (i, j));
     printf   ("%i %i 0\n", -getAvar (i, j),  getBvar (i, j));
     printf   ("%i %i 0\n",  getCvar (i, j), -getCvar (i, j)); }
}
