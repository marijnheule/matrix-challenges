#include <stdio.h>
#include <stdlib.h>

#define DIM	3

#define EXACTLYONE
#define ZEROTWO
//#define SBP
//#define ALLZERO
//#define FIXFALSE
//#define PALIN
//#define FIXDELTA
#define ATLEASTONE
//#define XOR

//#define DIAGONAL

//#define LADERMAN

#define RNDFIX
#define TWOFREELINES

#define RNDRANKONE

//#define RANK

//#define PERM

//#define PLANT
//#define PLANTT
//#define PLANTTT
//#define PLANTD

int seed, sdim, cdim, size, orig, pair, cube;

int cdelta (int x, int y, int z) {
  int a = x / DIM; int b = x % DIM;
  int c = y / DIM; int d = y % DIM;
  int e = z / DIM; int f = z % DIM;
  return (a == f) + (b == c) + (d == e);
}

int delta (int x, int y, int z) {
  int a = x / DIM; int b = x % DIM;
  int c = y / DIM; int d = y % DIM;
  int e = z / DIM; int f = z % DIM;
  if ((a != f) || (b != c) || (d != e)) return 0;
  if ((a == 0) || (b == 0) || (d == 0)) return 1;
  if ((a == 1) || (b == 1) || (d == 1)) return 2;
  return 3;
}


int atLeast (int *array, int size, int k, int var) {
  int i, j;

  printf ("%i 0\n", var + size*k - 1);
  printf ("-%i 0\n", var + size);
  printf ("%i -%i 0\n", array[0], var);

  for (i = 1; i < k; i++)
    for (j = 1; j < size; j++)
      printf ("%i -%i 0\n", var + (i-1)*size + j - 1, var + i*size + j);

  for (i = 0; i < k; i++)
    for (j = 1; j < size; j++) {
      printf ("-%i %i 0\n", var + i*size + j - 1, var + i*size + j);
      printf ("%i %i -%i 0\n", array[j], var + i*size + j - 1, var + i*size + j); }

  return var + size * k;
}

void twoFreeLines (int i) {
  printf ("-%i -%i -%i 0\n", i    , i + 4, i + 2);
  printf ("-%i -%i -%i 0\n", i    , i + 4, i + 5);
  printf ("-%i -%i -%i 0\n", i    , i + 4, i + 6);
  printf ("-%i -%i -%i 0\n", i    , i + 4, i + 7);
  printf ("-%i -%i -%i 0\n", i    , i + 4, i + 8);
  printf ("-%i -%i -%i 0\n", i    , i + 5, i + 1);
  printf ("-%i -%i -%i 0\n", i    , i + 5, i + 4);
  printf ("-%i -%i -%i 0\n", i    , i + 5, i + 6);
  printf ("-%i -%i -%i 0\n", i    , i + 5, i + 7);
  printf ("-%i -%i -%i 0\n", i    , i + 5, i + 8);
  printf ("-%i -%i -%i 0\n", i    , i + 7, i + 2);
  printf ("-%i -%i -%i 0\n", i    , i + 7, i + 3);
  printf ("-%i -%i -%i 0\n", i    , i + 7, i + 4);
  printf ("-%i -%i -%i 0\n", i    , i + 7, i + 5);
  printf ("-%i -%i -%i 0\n", i    , i + 7, i + 8);
  printf ("-%i -%i -%i 0\n", i    , i + 8, i + 1);
  printf ("-%i -%i -%i 0\n", i    , i + 8, i + 3);
  printf ("-%i -%i -%i 0\n", i    , i + 8, i + 4);
  printf ("-%i -%i -%i 0\n", i    , i + 8, i + 5);
  printf ("-%i -%i -%i 0\n", i    , i + 8, i + 7);

  printf ("-%i -%i -%i 0\n", i + 1, i + 3, i + 2);
  printf ("-%i -%i -%i 0\n", i + 1, i + 3, i + 5);
  printf ("-%i -%i -%i 0\n", i + 1, i + 3, i + 6);
  printf ("-%i -%i -%i 0\n", i + 1, i + 3, i + 7);
  printf ("-%i -%i -%i 0\n", i + 1, i + 3, i + 8);
  printf ("-%i -%i -%i 0\n", i + 1, i + 5, i + 0);
  printf ("-%i -%i -%i 0\n", i + 1, i + 5, i + 3);
  printf ("-%i -%i -%i 0\n", i + 1, i + 5, i + 6);
  printf ("-%i -%i -%i 0\n", i + 1, i + 5, i + 7);
  printf ("-%i -%i -%i 0\n", i + 1, i + 5, i + 8);
  printf ("-%i -%i -%i 0\n", i + 1, i + 6, i + 2);
  printf ("-%i -%i -%i 0\n", i + 1, i + 6, i + 3);
  printf ("-%i -%i -%i 0\n", i + 1, i + 6, i + 4);
  printf ("-%i -%i -%i 0\n", i + 1, i + 6, i + 5);
  printf ("-%i -%i -%i 0\n", i + 1, i + 6, i + 8);
  printf ("-%i -%i -%i 0\n", i + 1, i + 8, i + 0);
  printf ("-%i -%i -%i 0\n", i + 1, i + 8, i + 3);
  printf ("-%i -%i -%i 0\n", i + 1, i + 8, i + 6);
  printf ("-%i -%i -%i 0\n", i + 1, i + 8, i + 4);
  printf ("-%i -%i -%i 0\n", i + 1, i + 8, i + 5);

  printf ("-%i -%i -%i 0\n", i + 2, i + 3, i + 1);
  printf ("-%i -%i -%i 0\n", i + 2, i + 3, i + 4);
  printf ("-%i -%i -%i 0\n", i + 2, i + 3, i + 6);
  printf ("-%i -%i -%i 0\n", i + 2, i + 3, i + 7);
  printf ("-%i -%i -%i 0\n", i + 2, i + 3, i + 8);
  printf ("-%i -%i -%i 0\n", i + 2, i + 4, i + 0);
  printf ("-%i -%i -%i 0\n", i + 2, i + 4, i + 3);
  printf ("-%i -%i -%i 0\n", i + 2, i + 4, i + 6);
  printf ("-%i -%i -%i 0\n", i + 2, i + 4, i + 7);
  printf ("-%i -%i -%i 0\n", i + 2, i + 4, i + 8);
  printf ("-%i -%i -%i 0\n", i + 2, i + 6, i + 1);
  printf ("-%i -%i -%i 0\n", i + 2, i + 6, i + 4);
  printf ("-%i -%i -%i 0\n", i + 2, i + 6, i + 7);
  printf ("-%i -%i -%i 0\n", i + 2, i + 6, i + 3);
  printf ("-%i -%i -%i 0\n", i + 2, i + 6, i + 5);
  printf ("-%i -%i -%i 0\n", i + 2, i + 7, i + 0);
  printf ("-%i -%i -%i 0\n", i + 2, i + 7, i + 3);
  printf ("-%i -%i -%i 0\n", i + 2, i + 7, i + 6);
  printf ("-%i -%i -%i 0\n", i + 2, i + 7, i + 4);
  printf ("-%i -%i -%i 0\n", i + 2, i + 7, i + 5);
}

void condRank1 (int i, int var) {
  printf ("%i -%i -%i 0\n", var, i + 0, i + 4);
  printf ("%i -%i -%i 0\n", var, i + 0, i + 5);
  printf ("%i -%i -%i 0\n", var, i + 0, i + 7);
  printf ("%i -%i -%i 0\n", var, i + 0, i + 8);
  printf ("%i -%i -%i 0\n", var, i + 1, i + 3);
  printf ("%i -%i -%i 0\n", var, i + 1, i + 5);
  printf ("%i -%i -%i 0\n", var, i + 1, i + 6);
  printf ("%i -%i -%i 0\n", var, i + 1, i + 8);
  printf ("%i -%i -%i 0\n", var, i + 2, i + 3);
  printf ("%i -%i -%i 0\n", var, i + 2, i + 4);
  printf ("%i -%i -%i 0\n", var, i + 2, i + 6);
  printf ("%i -%i -%i 0\n", var, i + 2, i + 7);
  printf ("%i -%i -%i 0\n", var, i + 3, i + 7);
  printf ("%i -%i -%i 0\n", var, i + 3, i + 8);
  printf ("%i -%i -%i 0\n", var, i + 4, i + 6);
  printf ("%i -%i -%i 0\n", var, i + 4, i + 8);
  printf ("%i -%i -%i 0\n", var, i + 5, i + 6);
  printf ("%i -%i -%i 0\n", var, i + 5, i + 7);
}

void condSize1 (int i, int var) {
  printf ("%i -%i -%i 0\n", var, i + 0, i + 1);
  printf ("%i -%i -%i 0\n", var, i + 0, i + 2);
  printf ("%i -%i -%i 0\n", var, i + 1, i + 2);
  printf ("%i -%i -%i 0\n", var, i + 3, i + 4);
  printf ("%i -%i -%i 0\n", var, i + 3, i + 5);
  printf ("%i -%i -%i 0\n", var, i + 4, i + 5);
  printf ("%i -%i -%i 0\n", var, i + 6, i + 7);
  printf ("%i -%i -%i 0\n", var, i + 6, i + 8);
  printf ("%i -%i -%i 0\n", var, i + 7, i + 8);
  printf ("%i -%i -%i 0\n", var, i + 0, i + 3);
  printf ("%i -%i -%i 0\n", var, i + 0, i + 6);
  printf ("%i -%i -%i 0\n", var, i + 3, i + 6);
  printf ("%i -%i -%i 0\n", var, i + 1, i + 4);
  printf ("%i -%i -%i 0\n", var, i + 1, i + 7);
  printf ("%i -%i -%i 0\n", var, i + 4, i + 7);
  printf ("%i -%i -%i 0\n", var, i + 2, i + 5);
  printf ("%i -%i -%i 0\n", var, i + 2, i + 8);
  printf ("%i -%i -%i 0\n", var, i + 5, i + 8);
}

void noRank2 (int i) {
  printf ("-%i -%i 0\n", i    , i + 4);
  printf ("-%i -%i 0\n", i    , i + 5);
  printf ("-%i -%i 0\n", i    , i + 7);
  printf ("-%i -%i 0\n", i    , i + 8);
  printf ("-%i -%i 0\n", i + 1, i + 3);
  printf ("-%i -%i 0\n", i + 1, i + 5);
  printf ("-%i -%i 0\n", i + 1, i + 6);
  printf ("-%i -%i 0\n", i + 1, i + 8);
  printf ("-%i -%i 0\n", i + 2, i + 3);
  printf ("-%i -%i 0\n", i + 2, i + 4);
  printf ("-%i -%i 0\n", i + 2, i + 6);
  printf ("-%i -%i 0\n", i + 2, i + 7);
  printf ("-%i -%i 0\n", i + 3, i + 7);
  printf ("-%i -%i 0\n", i + 3, i + 8);
  printf ("-%i -%i 0\n", i + 4, i + 6);
  printf ("-%i -%i 0\n", i + 4, i + 8);
  printf ("-%i -%i 0\n", i + 5, i + 6);
  printf ("-%i -%i 0\n", i + 5, i + 7);
}

void noRank3 (int i) {
  printf ("-%i -%i -%i 0\n", i    , i + 4, i + 8);
  printf ("-%i -%i -%i 0\n", i    , i + 5, i + 7);
  printf ("-%i -%i -%i 0\n", i + 1, i + 3, i + 8);
  printf ("-%i -%i -%i 0\n", i + 1, i + 5, i + 6);
  printf ("-%i -%i -%i 0\n", i + 2, i + 4, i + 6);
  printf ("-%i -%i -%i 0\n", i + 2, i + 3, i + 7);
}

int getAvar (int i, int a) {
  return i * sdim * 3 + a + 1; }

int getBvar (int i, int b) {
  return i * sdim * 3 + b + 1 + sdim; }

int getCvar (int i, int c) {
  return i * sdim * 3 + c + 1 + 2 * sdim; }

int mostRankOne (int i, int var) {
  printf ("-%i -%i 0\n", var    , var + 1);
  printf ("-%i -%i 0\n", var    , var + 2);
  printf ("-%i -%i 0\n", var + 1, var + 2);
  condRank1 (getAvar (i, 0), var++);
  condRank1 (getBvar (i, 0), var++);
  condRank1 (getCvar (i, 0), var++);

  printf ("-%i -%i -%i 0\n", var    , var + 1, var + 2);
  condSize1 (getAvar (i, 0), var++);
  condSize1 (getBvar (i, 0), var++);
  condSize1 (getCvar (i, 0), var++);
  return var;
}

int getPair (int i, int a, int b) {
  return orig + i * sdim * sdim + a * sdim + b + 1; }

int getCube (int i, int a, int b, int c) {
  return orig + pair + i * sdim * sdim * sdim + a * sdim * sdim + b * sdim + c + 1; }

void printAunit (int step, int var) {
  int i;
  for (i = 0; i < sdim; i++) {
    if (i != var) printf("-");
    printf("%i 0\n", getAvar (step, i)); }
}

void printAbin (int step, int a, int b) {
  int i;
  for (i = 0; i < sdim; i++) {
    if ((i != a) && (i != b)) printf("-");
    printf("%i 0\n", getAvar (step, i)); }
}

void printAter (int step, int a, int b, int c) {
  int i;
  for (i = 0; i < sdim; i++) {
    if ((i != a) && (i != b) && (i != c)) printf("-");
    printf("%i 0\n", getAvar (step, i)); }
}

void printBunit (int step, int a) {
  int i;
  for (i = 0; i < sdim; i++) {
    if (i != a) printf("-");
    printf("%i 0\n", getBvar (step, i)); }
}

void printBbin (int step, int a, int b) {
  int i;
  for (i = 0; i < sdim; i++) {
    if ((i != a) && (i != b)) printf("-");
    printf("%i 0\n", getBvar (step, i)); }
}

void printBter (int step, int a, int b, int c) {
  int i;
  for (i = 0; i < sdim; i++) {
    if ((i != a) && (i != b) && (i != c)) printf("-");
    printf("%i 0\n", getBvar (step, i)); }
}

void printCunit (int step, int var) {
  int i;
  for (i = 0; i < sdim; i++) {
    if (i != var) printf("-");
    printf("%i 0\n", getCvar (step, i)); }
}

void printCbin (int step, int a, int b) {
  int i;
  for (i = 0; i < sdim; i++) {
    if ((i != a) && (i != b)) printf("-");
    printf("%i 0\n", getCvar (step, i)); }
}

void printCter (int step, int a, int b, int c) {
  int i;
  for (i = 0; i < sdim; i++) {
    if ((i != a) && (i != b) && (i != c)) printf("-");
    printf("%i 0\n", getCvar (step, i)); }
}

void printAMO (int* array, int size) {
  int i, j;
  for (i = 0; i < size; i++)
    for (j = i+1; j < size; j++)
      printf ("%i %i 0\n", -array[i], -array[j]);
}

void setPair (int i, int k) {
  int j;
  for (j = 0; j < sdim - 1; j++) {
     printf ("%i -%i 0\n", getBvar (i, j), getCvar (k, DIM*j % (sdim-1)));
     printf ("-%i %i 0\n", getBvar (i, j), getCvar (k, DIM*j % (sdim-1)));
     printf ("%i -%i 0\n", getAvar (i, j), getAvar (k, DIM*j % (sdim-1)));
     printf ("-%i %i 0\n", getAvar (i, j), getAvar (k, DIM*j % (sdim-1))); }
   printf ("%i -%i 0\n",   getAvar (i, j), getBvar (k, j));
   printf ("-%i %i 0\n",   getAvar (i, j), getBvar (k, j));
   printf ("%i -%i 0\n",   getAvar (i, j), getBvar (k, j));
   printf ("-%i %i 0\n",   getAvar (i, j), getBvar (k, j));
}

int printAMT (int* array, int size, int var) {
  printf ("%i %i %i 0\n", -array[0], -array[1], -array[2]);
  if (size == 3) return var;

  printf ("%i %i %i 0\n", -array[0], -array[1], -array[3]);
  printf ("%i %i %i 0\n", -array[0], -array[2], -array[3]);
  printf ("%i %i %i 0\n", -array[1], -array[2], -array[3]);
  if (size == 4) return var;

  printf ("%i %i 0\n",    -array[0],            var      );
  printf ("%i %i 0\n",    -array[1],            var      );
  printf ("%i %i %i 0\n", -array[0], -array[1], var + 1  );
  printf ("%i %i 0\n",    -array[2],            var + 1  );
  printf ("%i %i 0\n",    -array[3],            var + 1  );
  printf ("%i %i %i 0\n", -array[2], -array[3], var      );

  int i;
  for (i = 4; i < size; i++) array[i-2] = array[i];
  array[0] = var;
  array[1] = var + 1;

  return printAMT (array, size - 2, var + 2);

/*
  printf ("%i %i %i 0\n", -array[0], -array[1], -array[2]);
  printf ("%i %i 0\n", -array[0], var);
  printf ("%i %i %i 0\n", -array[0], -array[1], var + 1);
  printf ("%i %i %i 0\n", -array[1], var, var + 1);
  printf ("%i %i %i 0\n", -array[1], -array[2], var);
  printf ("%i %i 0\n", -array[2], var + 1);

  int i;
  for (i = 0; i < size - 3; i++) array[i] = array[i+3];
  array[size - 3] = var;
  array[size - 2] = var + 1;
  return printAMT (array, size - 1, var + 2);
*/
}

void printN1 (int* array, int size) {
  int i, j;
  for (i = 0; i < size; i++) {
    printf ("%i ", -array[i]);
    for (j = 0; j < size; j++) if (i != j) printf ("%i ", array[j]);
    printf ("0\n"); }
}

int printXOR (int* array, int size, int var) {
  if (size <  1) {
    printf ("0\n");
    return var; }

  if (size == 1) {
    printf ("%i 0\n", -array[0]);
    return var; }

  if (size == 2) {
    printf ("%i %i 0\n",  array[0], -array[1]);
    printf ("%i %i 0\n", -array[0],  array[1]);
    return var; }

  if (size == 3) {
    printf ("%i %i %i 0\n",  array[0],  array[1], -array[2]);
    printf ("%i %i %i 0\n",  array[0], -array[1],  array[2]);
    printf ("%i %i %i 0\n", -array[0],  array[1],  array[2]);
    printf ("%i %i %i 0\n", -array[0], -array[1], -array[2]);
    return var; }

  if (size == 4) {
    printf ("%i %i %i %i 0\n",  array[0],  array[1],  array[2], -array[3]);
    printf ("%i %i %i %i 0\n",  array[0],  array[1], -array[2],  array[3]);
    printf ("%i %i %i %i 0\n",  array[0], -array[1],  array[2],  array[3]);
    printf ("%i %i %i %i 0\n", -array[0],  array[1],  array[2],  array[3]);
    printf ("%i %i %i %i 0\n",  array[0], -array[1], -array[2], -array[3]);
    printf ("%i %i %i %i 0\n", -array[0],  array[1], -array[2], -array[3]);
    printf ("%i %i %i %i 0\n", -array[0], -array[1],  array[2], -array[3]);
    printf ("%i %i %i %i 0\n", -array[0], -array[1], -array[2],  array[3]);
    return var; }

  printf ("%i %i %i %i 0\n",  array[0],  array[1],  array[2], -var);
  printf ("%i %i %i %i 0\n",  array[0],  array[1], -array[2],  var);
  printf ("%i %i %i %i 0\n",  array[0], -array[1],  array[2],  var);
  printf ("%i %i %i %i 0\n", -array[0],  array[1],  array[2],  var);
  printf ("%i %i %i %i 0\n",  array[0], -array[1], -array[2], -var);
  printf ("%i %i %i %i 0\n", -array[0],  array[1], -array[2], -var);
  printf ("%i %i %i %i 0\n", -array[0], -array[1],  array[2], -var);
  printf ("%i %i %i %i 0\n", -array[0], -array[1], -array[2],  var);

  int i;
  for (i = 0; i < size - 3; i++) array[i] = array[i+3];
  array[size - 3] = var;
  return printXOR (array, size - 2, var + 1);
}

int main (int argc, char** argv) {
  seed = 0;
  size = atoi (argv[1]);
  int frac = 0;

  if (argc > 2) seed = atoi (argv[2]);
  srand (seed);

  if (argc > 3) frac = atoi (argv[3]);
  frac = 1000 - 10 * frac;

  sdim = DIM * DIM;
  cdim = DIM * DIM * DIM;
  orig = size * sdim * 3;
  pair = size * sdim * sdim;
  cube = size * sdim * sdim * sdim;

  int tmp = orig + pair + cube + 1;

  int nVar, nCls;
  int *toXOR;

  toXOR = (int*) malloc (sizeof (int) * size);

  nVar = orig + pair + cube;

  nVar += 100000;
  nCls = 0;
  nCls = 3 * (sdim + size);
  nCls += (pair + cube) * 3;
#ifdef XOR
  nVar += sdim * sdim * sdim * ((size - 3) / 2);
  nCls += sdim * sdim * sdim * (size - 2) * 4 ;
#endif
#ifdef ZEROTWO
  nVar += sdim * sdim * sdim * size * 2;
#endif
#ifdef PALIN
  nVar += size;
#endif

  printf ("p cnf %i %i\n", nVar, nCls);

  int i, j, k, l;
#ifdef ATLEASTONE
  for (i = 0; i < size; i++) {
    for (j = 0; j < sdim; j++) printf ("%i ", getAvar (i, j)); printf ("0\n");
    for (j = 0; j < sdim; j++) printf ("%i ", getBvar (i, j)); printf ("0\n");
    for (j = 0; j < sdim; j++) printf ("%i ", getCvar (i, j)); printf ("0\n"); }

  for (j = 0; j < 3 * sdim; j++) {
    for (i = 0; i < size; i++)
      printf ("%i ", i * DIM * DIM * DIM + j + 1);
    printf ("0\n"); }
#endif

#ifdef PLANTD
/*
  (a11 + a13)*(b33)*(c11 + c31 + c32) Y
  (a11 + a31)*(b11 + b13 + b23)*(c33) Y
*/
  printAbin (0, 0, 2); printBunit (0, 8); printCter (0, 0, 6, 7);
  printAbin (1, 0, 6); printCunit (1, 8); printBter (1, 0, 2, 5);

/*
  (a23 + a33)*(b31 + b32)*(c12) Y
  (a32 + a33)*(b21)*(c13 + c23) Y
*/
  printAbin (2, 5, 8); printBbin (2, 6, 7); printCunit (2, 1);
  printAbin (3, 7, 8); printCbin (3, 2, 5); printBunit (3, 3);

/*
  (a22 + a23)*(b32)*(c12 + c21 + c22) Y
  (a22 + a32)*(b12 + b21 + b22)*(c23) Y
*/
  printAbin (4, 4, 5); printBunit (4, 7); printCter (4, 1, 3, 4);
  printAbin (5, 4, 7); printCunit (5, 5); printBter (5, 1, 3, 4);

/*
  (a33)*(b11 + b21 + b31)*(c11 + c12 + c13) X
  (a11 + a33)*(b11 + b33)*(c11 + c33) X
  (a22 + a33)*(b21 + b32)*(c12 + c23) X
*/
  printAunit (6, 8); printBter (6, 0, 3, 6); printCter (6, 0, 1, 2);
  printAbin (7, 0, 8); printBbin (7, 0, 8); printCbin (7, 0, 8);
  printAbin (8, 4, 8); printBbin (8, 3, 7); printCbin (8, 1, 5);

//  printAunit (9, 0);
//  printAunit (10, 4);
/*
(a31 + a33)*(b11)*(c13 + c33)        (missing c_12)
(a13 + a33)*(b21 + b31 + b33)*(c11)
*/
  printBunit (11, 0); printAbin (11, 6, 8); printCbin (11, 2, 8);
  printCunit (12, 0); printAbin (12, 2, 8); printBbin (12, 6, 8);
/*
  (a11 + a12 + a31 + a32)*(b23)*(c21 + c31)
  (a11 + a13 + a21 + a23)*(b12 + b13)*(c32)
*/
  printBunit (13, 5);  printCbin (13, 3, 6);
  printCunit (14, 7);  printBbin (14, 1, 2);
  printBunit (15, 1);
  printCunit (16, 3);
//  printBunit (17, 3);
//  printCunit (18, 1);

//  setPair (19, 20);
  setPair (21, 22);

#endif

#ifdef PLANT
/*
  printAunit (size - 1, 0);
  printBunit (size - 1, 0);
  printAunit (size - 2, 8);
  printBunit (size - 2, 8);
  printAunit (size - 3, 1);
  printBunit (size - 3, 3);
  printAunit (size - 4, 2);
  printBunit (size - 4, 6);
  printAunit (size - 5, 5);
  printBunit (size - 5, 7);

  printAunit (0, 3);
  printAunit (1, 6);
  printAbin  (2, 0, 3);
  printAbin  (3, 3, 4);
  printAbin  (4, 0, 6);
  printAbin  (5, 6, 7);
  printAbin  (6, 2, 8);
  printAbin  (7, 4, 5);
  printAbin  (8, 2, 5);
  printAbin  (9, 7, 8);
*/
/*
  printAunit (0, 7);
  printAunit (1, 1);
  printAunit (2, 5);
  printAbin  (3, 6, 8);
  printAunit (4, 4);
  printAbin  (5, 0, 1);
  printAbin  (6, 0, 2);
  printAunit (8, 0);
  printAunit (10, 6);
//  printAbin  (12, 0, 5);
//  printAbin  (14, 6, 7);

  printAunit (size - 6, 2);
  printBunit (size - 6, 6);
  printAunit (size - 5, 8);
  printBunit (size - 5, 8);
  printAbin  (size - 4, 0, 4);
  printAbin  (size - 3, 0, 3);
  printAbin  (size - 2, 1, 4);
  printAbin  (size - 1, 2, 5);
*/


//  printAunit ( 0, 0);
//  printBunit ( 1, 0);
//  printAunit ( 2, 4   ); printBbin  ( 2, 0, 3);
//  printAbin  ( 3, 0, 1); printBunit ( 3, 4   );
//  printAbin  ( 4, 6, 8); printBunit ( 4, 7   );
//  printAunit ( 5, 5   ); printBbin  ( 5, 2, 8);




//  printAbin  (8, 0, 2); printBter  (8, 6, 7 ,8);
//  printAter  (9, 2, 5, 8); printBbin (9, 0, 6);


//  printAunit (11, 7   ); printBunit (11,  3);
//  printAunit (10, 1   ); printBunit (10, 5);


//  printAbin  (14, 6, 7); printBter (14, 3, 4, 5);
//  printAter  (15, 1, 4, 7); printBbin (15,  2, 5);

//  printAbin  (17, 1, 4); printBbin  (17, 3, 4);
//  printAbin  (18, 2, 5); printBbin  (18, 6, 7);
//  printAbin  (19, 0, 3); printBbin  (19, 0, 1);
//  printAbin  (20, 0, 4); printBbin  (20, 0, 4);
//  printAunit (21, 2   ); printBunit (21, 6);
//  printAunit (22, 8   ); printBunit (22, 8);

  printAunit (0, 6); printBunit (0, 1);
  printAunit (1, 3); printBunit (1, 2);

  printAbin (2, 2, 8); printBbin (2, 4, 7);
  printAbin (3, 4, 5); printBbin (3, 6, 8);

  printAbin (4, 4, 3); printBbin (4, 1, 0);
  printAbin (5, 0, 3); printBbin (5, 1, 4);
  printAbin (6, 6, 7); printBbin (6, 0, 2);
  printAbin (7, 0, 6); printBbin (7, 2, 5);
/*


  printAbin (8, 7, 8); printBbin (8, 6, 7);
  printAbin (11, 2, 5); printBbin (11, 5, 8);
*/

  printBunit (14, 4);
  printAunit (15, 4);
  printBunit (17, 5);
  printAunit (16, 7);

  printAunit (18, 1); printBunit (18, 3);
  printAunit (19, 5); printBunit (19, 7);
  printAunit (20, 0); printBunit (20, 0);
  printAunit (21, 2); printBunit (21, 6);
  printAunit (22, 8); printBunit (22, 8);
#endif


#ifdef DIAGONAL
  for (i = 0; i < size; i++) {
    noRank3 (getAvar (i, 0));
    noRank3 (getBvar (i, 0));
    noRank3 (getCvar (i, 0)); }

  int diag = 0;
  // fix all the CA-AB-BC elements with either A, B, or C = 1
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++)
        if (delta (j, k, l) == 1) {
          printf ("%i 0\n", getCube (diag++, j, k, l)); }

  // prevent two CA-AB-BC elements in the same product if they overlap


  // break symmetry on the remaining CA-AB-BC elements
/*
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++)
        if (delta (j, k, l) > 1) {
          printf ("%i 0\n", getCube (diag++, j, k, l)); }
*/

#endif



#ifdef LADERMAN
/*
(a13)*(b32)*(c21)
(a23)*(b31)*(c12)
(b21)*(c13)
(a12)*(c31)
(b22)*(c23)
(a22)*(c32)
*/

 printAunit (0,2); printBunit (0,7); printCunit (0,3);
 printAunit (1,5); printBunit (1,6); printCunit (1,1);

 printBunit (2,3); printCunit (2,2);
 printAunit (3,1); printCunit (3,6);

 printBunit (4,4); printCunit (4,5);
 printAunit (5,4); printCunit (5,7);

/*
(a13 + a33)*(b21 + b31)*(c11 + c31)
(a12 + a13)*(b31 + b33)*(c11 + c13)
(a11 + a31)*(b12 + b22)*(c21 + c31)
(a21 + a22)*(b11 + b13)*(c12 + c13)

(a21 + a31)*(b11 + b21)*(c12 + c32)
(a11 + a12)*(b12 + b13)*(c21 + c23)
(a23 + a33)*(b22 + b32)*(c22 + c32)
(a22 + a23)*(b32 + b33)*(c22 + c23)
*/
/*
 printAbin (6, 2, 8); printBbin (6, 3, 6); printCbin (6, 0, 6);
 printAbin (7, 1, 2); printBbin (7, 6, 8); printCbin (7, 0, 2);
 printAbin (8, 0, 6); printBbin (8, 1, 4); printCbin (8, 3, 6);
 printAbin (9, 3, 4); printBbin (9, 0, 2); printCbin (9, 1, 2);

 printAbin(10, 3, 6); printBbin(10, 0, 3); printCbin(10, 1, 7);
 printAbin(11, 0, 1); printBbin(11, 1, 2); printCbin(11, 3, 5);
 printAbin(12, 5, 8); printBbin(12, 4, 7); printCbin(12, 4, 7);
 printAbin(13, 4, 5); printBbin(13, 7, 8); printCbin(13, 4, 5);
*/

/*
(a31)*(b13)
(a33)*(b33)
(a21)*(b12)*(c22)
(a32)*(b23)*(c33)
(a11)*(b11)*(c11)
*/

 printAunit(18,6); printBunit(18,2);
 printAunit(19,8); printBunit(19,8);
 printAunit(20,3); printBunit(20,1); printCunit(20,4);
 printAunit(21,7); printBunit(21,5); printCunit(21,8);
 printAunit(22,0); printBunit(22,0); printCunit(22,0);
#endif

#ifdef RANK
  for (i = 0; i < size; i++) {
    noRank3 (getAvar (i, 0));
    noRank3 (getBvar (i, 0));
    noRank3 (getCvar (i, 0));
  }
/*
  for (i = 0; i < size; i++) {
    if (rand() % 1000 > frac) noRank2 (getAvar (i, 0));
    if (rand() % 1000 > frac) noRank2 (getBvar (i, 0));
    if (rand() % 1000 > frac) noRank2 (getCvar (i, 0));
  }
*/
  // pick dim^3 - size entries for Rank2 elements

#endif

#ifdef TWOFREELINES
  for (i = 0; i < size; i++) {
    twoFreeLines (getAvar (i, 0));
    twoFreeLines (getBvar (i, 0));
    twoFreeLines (getCvar (i, 0));
  }
#endif

#ifdef PLANTTT
/*
  printAunit ( 2, 0);
  printBunit ( 3, 3);
  printCunit ( 3, 0);
  printCunit ( 4, 3);
  printBunit ( 5, 5);
  printCunit ( 6, 0);

  printAunit (19, 4);
  printBunit (20, 7);
  printCunit (21, 7);
  printCunit (22, 5);

  printBunit ( 8, 8);
  printBunit ( 9, 0);
  printBunit (10, 1);
  printBunit (14, 0);
  printBunit (15, 1);
*/

  tmp = mostRankOne ( 2, tmp);
  tmp = mostRankOne ( 3, tmp);
  tmp = mostRankOne ( 4, tmp);
  tmp = mostRankOne ( 5, tmp);
  tmp = mostRankOne ( 6, tmp);
  tmp = mostRankOne ( 8, tmp);
  tmp = mostRankOne ( 9, tmp);
  tmp = mostRankOne (10, tmp);
  tmp = mostRankOne (11, tmp);
  tmp = mostRankOne (13, tmp);
  tmp = mostRankOne (14, tmp);
  tmp = mostRankOne (15, tmp);
  tmp = mostRankOne (16, tmp);
  tmp = mostRankOne (17, tmp);
  tmp = mostRankOne (18, tmp);
  tmp = mostRankOne (19, tmp);
  tmp = mostRankOne (20, tmp);
  tmp = mostRankOne (21, tmp);
  tmp = mostRankOne (22, tmp);

/*
  noRank2 (getAvar ( 2, 0));
  noRank2 (getAvar ( 3, 0));
  noRank2 (getAvar ( 6, 0));
  noRank2 (getAvar ( 8, 0));
  noRank2 (getAvar (10, 0));
  noRank2 (getAvar (11, 0));
  noRank2 (getAvar (13, 0));
  noRank2 (getAvar (14, 0));
  noRank2 (getAvar (15, 0));
  noRank2 (getAvar (16, 0));
  noRank2 (getAvar (17, 0));
  noRank2 (getAvar (18, 0));
  noRank2 (getAvar (19, 0));
  noRank2 (getAvar (20, 0));
  noRank2 (getAvar (21, 0));
  noRank2 (getAvar (22, 0));
*/
/*
  noRank2 (getBvar ( 3, 0));
  noRank2 (getBvar ( 4, 0));
  noRank2 (getBvar ( 5, 0));
  noRank2 (getBvar ( 8, 0));
  noRank2 (getBvar ( 9, 0));
  noRank2 (getBvar (10, 0));
  noRank2 (getBvar (11, 0));
  noRank2 (getBvar (13, 0));
  noRank2 (getBvar (14, 0));
  noRank2 (getBvar (15, 0));
  noRank2 (getBvar (17, 0));
  noRank2 (getBvar (18, 0));
  noRank2 (getBvar (19, 0));
  noRank2 (getBvar (20, 0));
*/
/*
  noRank2 (getCvar ( 2, 0));
  noRank2 (getCvar ( 3, 0));
  noRank2 (getCvar ( 4, 0));
  noRank2 (getCvar ( 5, 0));
  noRank2 (getCvar ( 6, 0));
  noRank2 (getCvar ( 9, 0));
  noRank2 (getCvar (10, 0));
  noRank2 (getCvar (11, 0));
  noRank2 (getCvar (13, 0));
  noRank2 (getCvar (14, 0));
  noRank2 (getCvar (16, 0));
  noRank2 (getCvar (17, 0));
  noRank2 (getCvar (18, 0));
  noRank2 (getCvar (21, 0));
  noRank2 (getCvar (22, 0));
*/

//  setPair (0,0);
//  setPair (1,7);

  int* atl;
  atl = (int *) malloc (sizeof (int) * size);

  for (i = 0; i < size; i++) {
    condRank1 (getAvar (i, 0), tmp); atl[i] = -tmp++; }
  tmp = atLeast (atl, size, 14, tmp);
  for (i = 0; i < size; i++) {
    condRank1 (getBvar (i, 0), tmp); atl[i] = -tmp++; }
  tmp = atLeast (atl, size, 14, tmp);
  for (i = 0; i < size; i++) {
    condRank1 (getCvar (i, 0), tmp); atl[i] = -tmp++; }
  tmp = atLeast (atl, size, 14, tmp);

  printf("%i 0\n", getCube ( 0, 8, 8, 8));
  printf("%i 0\n", getCube ( 1, 7, 5, 8));
  printf("%i 0\n", getCube ( 7, 4, 5, 7));
  printf("%i 0\n", getCube (12, 8, 7, 5));
  printf("%i 0\n", getCube (19, 4, 4, 4));
  printf("%i 0\n", getCube (20, 5, 7, 4));
  printf("%i 0\n", getCube (21, 5, 8, 7));
  printf("%i 0\n", getCube (22, 7, 4, 5));

#endif

#ifdef PLANTT
/*
  for (i = 0; i < size; i++) {
    noRank3 (getAvar (i, 0));
    noRank3 (getBvar (i, 0));
    noRank3 (getCvar (i, 0));
  }
*/
/*
  noRank2 (getAvar ( 0, 0));
  noRank2 (getAvar ( 5, 0));
  noRank2 (getAvar ( 6, 0));
  noRank2 (getAvar ( 7, 0));
  noRank2 (getAvar ( 8, 0));
  noRank2 (getAvar ( 9, 0));
  noRank2 (getAvar (10, 0));
  noRank2 (getAvar (11, 0));
  noRank2 (getAvar (12, 0));
  noRank2 (getAvar (13, 0));
  noRank2 (getAvar (14, 0));
  noRank2 (getAvar (15, 0));
  noRank2 (getAvar (16, 0));
  noRank2 (getAvar (18, 0));
  noRank2 (getAvar (19, 0));
  noRank2 (getAvar (21, 0));
*/
  noRank2 (getBvar ( 0, 0));
  noRank2 (getBvar ( 3, 0));
  noRank2 (getBvar ( 4, 0));
  noRank2 (getBvar ( 5, 0));
  noRank2 (getBvar ( 6, 0));
  noRank2 (getBvar ( 7, 0));
  noRank2 (getBvar ( 9, 0));
  noRank2 (getBvar (10, 0));
  noRank2 (getBvar (12, 0));
  noRank2 (getBvar (14, 0));
  noRank2 (getBvar (15, 0));
  noRank2 (getBvar (16, 0));
  noRank2 (getBvar (17, 0));
  noRank2 (getBvar (18, 0));
  noRank2 (getBvar (19, 0));
  noRank2 (getBvar (20, 0));
  noRank2 (getBvar (21, 0));
  noRank2 (getBvar (22, 0));

  noRank2 (getCvar ( 0, 0));
  noRank2 (getCvar ( 3, 0));
  noRank2 (getCvar ( 4, 0));
  noRank2 (getCvar ( 5, 0));
  noRank2 (getCvar ( 6, 0));
  noRank2 (getCvar ( 8, 0));
  noRank2 (getCvar ( 9, 0));
  noRank2 (getCvar (10, 0));
  noRank2 (getCvar (13, 0));
  noRank2 (getCvar (14, 0));
  noRank2 (getCvar (16, 0));
  noRank2 (getCvar (21, 0));
  noRank2 (getCvar (22, 0));

  printf("%i 0\n", getCube ( 0, 0, 0, 0));  //printAunit (0, 0);
  printf("%i 0\n", getCube ( 1, 0, 1, 3));
  printf("%i 0\n", getCube ( 2, 0, 2, 6));
  printf("%i 0\n", getCube ( 3, 1, 3, 0));  //printBunit (3, 3);
  printf("%i 0\n", getCube ( 4, 1, 4, 3));
  printf("%i 0\n", getCube ( 5, 1, 5, 6));  //printAunit (5, 1);
  printf("%i 0\n", getCube ( 6, 2, 6, 0));
  printf("%i 0\n", getCube ( 7, 2, 7, 3));  //printCunit (7, 3);
  printf("%i 0\n", getCube ( 4, 2, 8, 6));

  printf("%i 0\n", getCube ( 8, 3, 0, 1));  //printCunit (8, 1);
  printf("%i 0\n", getCube ( 9, 3, 1, 4));
  printf("%i 0\n", getCube (10, 3, 2, 7));
  printf("%i 0\n", getCube ( 2, 4, 3, 1));
  printf("%i 0\n", getCube (11, 4, 4, 4));
  printf("%i 0\n", getCube (12, 4, 5, 7));  //printAunit (12, 4);
  printf("%i 0\n", getCube ( 1, 5, 6, 1));
  printf("%i 0\n", getCube (13, 5, 7, 4));
  printf("%i 0\n", getCube (14, 5, 8, 7));  //printBunit (14, 8);

  printf("%i 0\n", getCube (15, 6, 0, 2));  //printAunit (15, 6);
  printf("%i 0\n", getCube (16, 6, 1, 5));  //printAunit (16, 6);
  printf("%i 0\n", getCube (11, 6, 2, 8));
  printf("%i 0\n", getCube (17, 7, 3, 2));
  printf("%i 0\n", getCube (18, 7, 4, 5));
  printf("%i 0\n", getCube (19, 7, 5, 8));  //printCunit (19, 8);
  printf("%i 0\n", getCube (20, 8, 6, 2));  //printBunit (20, 6);
  printf("%i 0\n", getCube (21, 8, 7, 5));  //printBunit (21, 7); printAunit (21, 8);
  printf("%i 0\n", getCube (22, 8, 8, 8));  //printBunit (22, 8);
#endif

/*
  0 x 0
  1 x 3
  2 x 6
  3 x 1
  4 x 4
  5 x 7
  6 x 2
  7 x 5
  8 x 8
*/

 int fixed, skip;

#ifdef RNDFIX
  for (i = 0; i < size; i++) {
    noRank3 (getAvar (i, 0));
    noRank3 (getBvar (i, 0));
    noRank3 (getCvar (i, 0)); }

  int **core;
  core = (int **) malloc (sizeof(int*) * DIM * DIM * DIM);
  for (i = 0; i < DIM * DIM * DIM; i++) {
    core[i] = (int *) malloc (sizeof(int) * 3);
    core[i][0] = core[i][1] = core[i][2] = -1; }

  fixed = 0;
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++)
        if (cdelta (j, k, l) == 3) {
          core[fixed][0] = j;
          core[fixed][1] = k;
          core[fixed][2] = l;
          fixed++; }

  int diff = DIM * DIM * DIM - size;

  for (i = 0; i < diff; i++) {
    int a = rand () % fixed;
    int b = rand () % fixed;
    if (i == 0) { a = 0; b = 26; }
    if (i == 1) { a = 1; b = 23; }
    if (i == 2) { a = 7; b = 15; }
    if (i == 3) { a = 9; b =  0; }

    while (1) {
      printf ("c : a %i b %i\n", a, b);
      int xa = core[a][0] % DIM; int xb = core[b][0] % DIM;
      int ya = core[a][1] % DIM; int yb = core[b][1] % DIM;
      int za = core[a][2] % DIM; int zb = core[b][2] % DIM;
      if ((xa != xb) && (ya != yb) && (za != zb)) break;
      b = rand () % fixed; }

    printf ("%i 0\n", getCube (i, core[a][0], core[a][1], core[a][2]));
    printf ("%i 0\n", getCube (i, core[b][0], core[b][1], core[b][2]));

    if (a > b) { int swap = a; a = b; b = swap; }
    fixed--; core[b][0] = core[fixed][0]; core[b][1] = core[fixed][1]; core[b][2] = core[fixed][2];
    fixed--; core[a][0] = core[fixed][0]; core[a][1] = core[fixed][1]; core[a][2] = core[fixed][2];
  }
/*
  int* atl;
  atl = (int *) malloc (sizeof (int) * size);

  for (i = 0; i < size; i++) {
    condRank1 (getAvar (i, 0), tmp); atl[i] = -tmp++; }
  tmp = atLeast (atl, size, 14, tmp);
  for (i = 0; i < size; i++) {
    condRank1 (getBvar (i, 0), tmp); atl[i] = -tmp++; }
  tmp = atLeast (atl, size, 14, tmp);
  for (i = 0; i < size; i++) {
    condRank1 (getCvar (i, 0), tmp); atl[i] = -tmp++; }
  tmp = atLeast (atl, size, 14, tmp);
*/
  for (i = 0; i < fixed; i++) {
    tmp = mostRankOne (diff + i, tmp);
    printf ("%i 0\n", getCube (diff + i, core[i][0], core[i][1], core[i][2])); }
#endif

#ifdef PALIN
   int odd = size % 2;
   for (i = 0; i < size - odd; i++) {
     int offset = -2 * (i % 2) + 1;
     for (j = 0; j < sdim - 1; j++) {
       printf ("%i %i %i 0\n",  tmp + i,  getAvar (i, j), -getBvar (i + offset, DIM*j % (sdim-1)));
       printf ("%i %i %i 0\n",  tmp + i, -getAvar (i, j),  getBvar (i + offset, DIM*j % (sdim-1)));
       printf ("%i %i %i 0\n", -tmp - i,  getAvar (i, j), -getBvar (i         , DIM*j % (sdim-1)));
       printf ("%i %i %i 0\n", -tmp - i, -getAvar (i, j),  getBvar (i         , DIM*j % (sdim-1))); }
     printf ("%i %i %i 0\n",  tmp + i,  getAvar (i, j), -getBvar (i + offset, j));
     printf ("%i %i %i 0\n",  tmp + i, -getAvar (i, j),  getBvar (i + offset, j));
     printf ("%i %i %i 0\n", -tmp - i,  getAvar (i, j), -getBvar (i         , j));
     printf ("%i %i %i 0\n", -tmp - i, -getAvar (i, j),  getBvar (i         , j)); }

   if (odd) {
     i = size - odd;
     for (j = 0; j < sdim - 1; j++) {
       printf ("%i %i 0\n",  getAvar (i, j), -getBvar (i         , DIM*j % (sdim-1)));
       printf ("%i %i 0\n", -getAvar (i, j),  getBvar (i         , DIM*j % (sdim-1))); }
     printf ("%i %i 0\n",  getAvar (i, j), -getBvar (i         , j));
     printf ("%i %i 0\n", -getAvar (i, j),  getBvar (i         , j)); }

   for (i = 0; i < size - 1; i++)
     printf ("-%i %i 0\n", tmp + i, tmp + i + 1);

   tmp += size;
#endif



#ifdef RNDRANKONE
  for (i = DIM*DIM*DIM-size; i < size; i++) {
    int r = rand ();
    if (r % 1000 < frac) continue;
    r = r % 4;
    if ((r != 0) && (r != 3)) noRank2 (getAvar (i,0));
    if ((r != 1) && (r != 3)) noRank2 (getBvar (i,0));
    if ((r != 2) && (r != 3)) noRank2 (getCvar (i,0));
  }
#endif

#ifdef FIXDELTA
/*
  int fixed = 0;
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++)
        if (delta (j, k, l) && (fixed < size)) {
          int start = fixed - 1; if (start < 0) start = 0;
          int end   = fixed + 1; if (end > size) end = size;
          for (i = start; i < end; i++)
             printf ("%i ", getCube (i, j, k, l));
          printf ("0\n");
          fixed++; }
*/

  fixed = 0;
  skip  = cdim - size;
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++)
        if (delta (j, k, l) && (fixed < size)) {
          for (i = 0; i < size; i++) {
            if ((rand () % size) - skip < 0) {
              skip--; continue; }
            if (i != fixed) printf ("-");
            printf ("%i 0\n", getCube (i, j, k, l)); }
          fixed++; }

#endif

#ifdef PERM
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) printf ("%i ", tmp + size * i + j + 1);
    printf("0\n");
    for (j = 0; j < size; j++)
      for (k = j + 1; k < size; k++)
        printf ("-%i -%i 0\n", tmp + size * i + j + 1, tmp + size * i + k + 1); }

  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++) {
       printf ("%i -%i 0\n", tmp + size * i + j + 1, tmp + size * j + i + 1);
       printf ("-%i %i 0\n", tmp + size * i + j + 1, tmp + size * j + i + 1); }

  for (i = 0; i < size; i++)
    for (j = i + 1; j < size; j++) { // changed to i + 1
      for (k = 0; k < sdim - 1; k++) {
        printf ("-%i %i -%i 0\n", tmp + size * i + j + 1, getAvar (i, k), getBvar (j, DIM*k % (sdim-1)));
        printf ("-%i -%i %i 0\n", tmp + size * i + j + 1, getAvar (i, k), getBvar (j, DIM*k % (sdim-1)));
        printf ("-%i %i -%i 0\n", tmp + size * i + j + 1, getCvar (i, k), getCvar (j, DIM*k % (sdim-1)));
        printf ("-%i -%i %i 0\n", tmp + size * i + j + 1, getCvar (i, k), getCvar (j, DIM*k % (sdim-1))); }
      printf ("-%i %i -%i 0\n", tmp + size * i + j + 1, getAvar (i, k), getBvar (j, k));
      printf ("-%i -%i %i 0\n", tmp + size * i + j + 1, getAvar (i, k), getBvar (j, k));
      printf ("-%i %i -%i 0\n", tmp + size * i + j + 1, getCvar (i, k), getCvar (j, k));
      printf ("-%i -%i %i 0\n", tmp + size * i + j + 1, getCvar (i, k), getCvar (j, k)); }

  tmp += size * size;
#endif

  // define AB pairs
  for (i = 0; i < size; i++)
    for (j = 0; j < sdim; j++)
      for (k = 0; k < sdim; k++) {
        printf ("%i -%i -%i 0\n", getPair (i, j, k), getAvar (i, j), getBvar (i, k));
        printf ("-%i %i 0\n",     getPair (i, j, k), getAvar (i, j));
        printf ("-%i %i 0\n",     getPair (i, j, k), getBvar (i, k)); }

  // define ABC triplets
  for (i = 0; i < size; i++)
    for (j = 0; j < sdim; j++)
      for (k = 0; k < sdim; k++)
        for (l = 0; l < sdim; l++) {
          printf ("%i -%i -%i 0\n", getCube (i, j, k, l), getPair (i, j, k), getCvar (i, l));
          printf ("-%i %i 0\n",     getCube (i, j, k, l), getPair (i, j, k));
          printf ("-%i %i 0\n",     getCube (i, j, k, l), getCvar (i, l)); }

#ifdef XOR
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++) {
        for (i = 0; i < size; i++) toXOR[i] = getCube (i, j, k, l);
        if (delta (j, k, l))
  #ifdef EXACTLYONE
          continue;
  #else
          toXOR[0] *= -1;
  #endif
        tmp = printXOR (toXOR, size, tmp); }
#endif

#ifdef SBP
//  for (i = 0; i < sdim - 1; i++) // for DIM 2
  for (i = 0; i < sdim; i++)
    for (j = 0; j < sdim; j++) {
      if (i != j) printf ("-");
      printf ("%i 0\n", getAvar (i, j)); }

  for (i = sdim; i < size - 1; i++) {
    printf ("-%i %i 0\n", sdim * 3 * i + 1, sdim * 3 * (i+1) + 1);
    printf ("%i -%i 0\n", tmp, sdim * 3 * (i) + 1);
    printf ("%i %i 0\n", tmp, sdim * 3 * (i+1) + 1);
    for (j = 1; j < sdim * 2; j++) {
      printf ("-%i -%i %i 0\n", tmp, sdim * 3 * i + j + 1, sdim * 3 * (i+1) + j + 1);
      printf ("%i -%i -%i 0\n", tmp + 1, tmp, sdim * 3 * (i) + j + 1);
      printf ("%i -%i %i 0\n",  tmp + 1, tmp, sdim * 3 * (i+1) + j + 1);
      tmp++;
    }
    tmp++;
  }
#endif

#ifdef EXACTLYONE
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++)
        if (delta (j, k, l)) {
          for (i = 0; i < size; i++) printf ("%i ", getCube (i, j, k, l));
          printf ("0\n"); int h;
          for (h = 0; h < size; h++)
            for (i = h + 1; i < size; i++)
              printf ("-%i -%i 0\n", getCube (h, j, k, l), getCube (i, j, k, l)); }
#endif

#ifdef ALLZERO
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++) {
        int r = rand () % 1000;
        int cd = cdelta(j, k, l) + 1;
        if (cd == 3) cd = 2;
        if (cd == 4) cd = 1000;
        if (cd >  1) cd = 1000;
//        printf ("c %i %i %i\n", r, cdelta(j, k, l), frac);
//        if (!delta (j, k, l) && (rand() % 1000 > frac))
//        if (!cdelta (j, k, l) && (rand() % 1000 > frac))
//        if (((cd == 0) && (r > 800)) || ((cd == 1) && (r > frac)))
//        if (r > frac * cd)
        if (r > 500 * cd)
          for (i = 0; i < size; i++) printf("-%i 0\n", getCube (i, j, k, l));
       }

#endif

#ifdef FIXFALSE
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++)
        if (!delta (j, k, l))
          for (i = 0; i < size; i++)
            if (rand() % 1000 > frac) printf ("-%i 0\n", getCube (i, j, k, l));
#endif

#ifdef ZEROTWO
  for (j = 0; j < sdim; j++)
    for (k = 0; k < sdim; k++)
      for (l = 0; l < sdim; l++) {
        for (i = 0; i < size; i++) toXOR[i] = getCube (i, j, k, l);
        if (!delta (j, k , l)) {
          printN1 (toXOR, size);
          tmp = printAMT (toXOR, size, tmp); }
      }
#endif
}
