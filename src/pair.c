#include <stdio.h>
#include <stdlib.h>

//#define NOMATCH

int main (int argc, char** argv) {
  FILE *exp;

  int i, tmp;
  char c;
  int on[27];
  int in[27];
  int line = 0;
  int sum = 0;
  int set = 0;

  exp = stdin;
  if (argc > 1) {
    exp = fopen (argv[1], "r"); }


  for (i = 0; i < 27; i++) { on[i] = 0; in[i] = 0; }
  while (1) {
    tmp = fscanf (exp, "%c", &c);
    if (tmp == EOF) break;
    if (c == '(') continue;
    if (c == ')') continue;
    if (c == ' ') continue;
    if (c == '+') continue;
    if (c == '*') continue;

    if (c == '\n') {
      if (on[0] & on[ 9] & on [18]) { on[0] = 3; on [ 9] = 3; on[18] = 3; }
      if (on[0] & on[10] & on [21]) { on[0] = 3; on [10] = 3; on[21] = 3; }
      if (on[0] & on[11] & on [24]) { on[0] = 3; on [11] = 3; on[24] = 3; }

      if (on[1] & on[12] & on [18]) { on[1] = 3; on [12] = 3; on[18] = 3; }
      if (on[1] & on[13] & on [21]) { on[1] = 3; on [13] = 3; on[21] = 3; }
      if (on[1] & on[14] & on [24]) { on[1] = 3; on [14] = 3; on[24] = 3; }

      if (on[2] & on[15] & on [18]) { on[2] = 3; on [15] = 3; on[18] = 3; }
      if (on[2] & on[16] & on [21]) { on[2] = 3; on [16] = 3; on[21] = 3; }
      if (on[2] & on[17] & on [24]) { on[2] = 3; on [17] = 3; on[24] = 3; }

      if (on[3] & on[ 9] & on [19]) { on[3] = 3; on [ 9] = 3; on[19] = 3; }
      if (on[3] & on[10] & on [22]) { on[3] = 3; on [10] = 3; on[22] = 3; }
      if (on[3] & on[11] & on [25]) { on[3] = 3; on [11] = 3; on[25] = 3; }

      if (on[4] & on[12] & on [19]) { on[4] = 3; on [12] = 3; on[19] = 3; }
      if (on[4] & on[13] & on [22]) { on[4] = 3; on [13] = 3; on[22] = 3; }
      if (on[4] & on[14] & on [25]) { on[4] = 3; on [14] = 3; on[25] = 3; }

      if (on[5] & on[15] & on [19]) { on[5] = 3; on [15] = 3; on[19] = 3; }
      if (on[5] & on[16] & on [22]) { on[5] = 3; on [16] = 3; on[22] = 3; }
      if (on[5] & on[17] & on [25]) { on[5] = 3; on [17] = 3; on[25] = 3; }

      if (on[6] & on[ 9] & on [20]) { on[6] = 3; on [ 9] = 3; on[20] = 3; }
      if (on[6] & on[10] & on [23]) { on[6] = 3; on [10] = 3; on[23] = 3; }
      if (on[6] & on[11] & on [26]) { on[6] = 3; on [11] = 3; on[26] = 3; }

      if (on[7] & on[12] & on [20]) { on[7] = 3; on [12] = 3; on[20] = 3; }
      if (on[7] & on[13] & on [23]) { on[7] = 3; on [13] = 3; on[23] = 3; }
      if (on[7] & on[14] & on [26]) { on[7] = 3; on [14] = 3; on[26] = 3; }

      if (on[8] & on[15] & on [20]) { on[8] = 3; on [15] = 3; on[20] = 3; }
      if (on[8] & on[16] & on [23]) { on[8] = 3; on [16] = 3; on[23] = 3; }
      if (on[8] & on[17] & on [26]) { on[8] = 3; on [17] = 3; on[26] = 3; }

      int count = 0;
      for (i = 0; i < 27; i++) if (on[i] == 3) count++;

      if ((count == 3) && (set == 0)) {
        set = 1;
        for (i = 0; i < 27; i++) { if (on[i] == 3) in[i] = 3, on[i] = 1; }
        goto next_line; }

      if ((count == 3) && (set == 1)) {
        int u,v,w,x,y,z;

        if ((on[0]&2) || (on[1]&2) || (on[2]&2)) u = 1;
        if ((on[3]&2) || (on[4]&2) || (on[5]&2)) u = 2;
        if ((on[6]&2) || (on[7]&2) || (on[8]&2)) u = 3;

        if ((on[ 9]&2) || (on[10]&2) || (on[11]&2)) v = 1;
        if ((on[12]&2) || (on[13]&2) || (on[14]&2)) v = 2;
        if ((on[15]&2) || (on[16]&2) || (on[17]&2)) v = 3;

        if ((on[18]&2) || (on[19]&2) || (on[20]&2)) w = 1;
        if ((on[21]&2) || (on[22]&2) || (on[23]&2)) w = 2;
        if ((on[24]&2) || (on[25]&2) || (on[26]&2)) w = 3;

        if ((in[0]&2) || (in[1]&2) || (in[2]&2)) x = 1;
        if ((in[3]&2) || (in[4]&2) || (in[5]&2)) x = 2;
        if ((in[6]&2) || (in[7]&2) || (in[8]&2)) x = 3;

        if ((in[ 9]&2) || (in[10]&2) || (in[11]&2)) y = 1;
        if ((in[12]&2) || (in[13]&2) || (in[14]&2)) y = 2;
        if ((in[15]&2) || (in[16]&2) || (in[17]&2)) y = 3;

        if ((in[18]&2) || (in[19]&2) || (in[20]&2)) z = 1;
        if ((in[21]&2) || (in[22]&2) || (in[23]&2)) z = 2;
        if ((in[24]&2) || (in[25]&2) || (in[26]&2)) z = 3;

#ifndef NOMATCH
//        if ((u != x) && (v != y) && (w != z)) {
        if (((u != x) && (v != y) && (w != z)) || ((u == x) && (v == y)) || ((u == x) && (w == z)) || ((v == y) && (w == z)) ) {
#endif
          for (i = 0; i < 27; i++) if (in[i] == 3) on[i] = 3;
          set = 2;
#ifndef NOMATCH
        }
#endif
      }

      printf("("); int first = 1;
      if (on[ 0]&2) { if (first) first = 0; else printf (" + "); printf("a11"); }
      if (on[ 1]&2) { if (first) first = 0; else printf (" + "); printf("a12"); }
      if (on[ 2]&2) { if (first) first = 0; else printf (" + "); printf("a13"); }
      if (on[ 3]&2) { if (first) first = 0; else printf (" + "); printf("a21"); }
      if (on[ 4]&2) { if (first) first = 0; else printf (" + "); printf("a22"); }
      if (on[ 5]&2) { if (first) first = 0; else printf (" + "); printf("a23"); }
      if (on[ 6]&2) { if (first) first = 0; else printf (" + "); printf("a31"); }
      if (on[ 7]&2) { if (first) first = 0; else printf (" + "); printf("a32"); }
      if (on[ 8]&2) { if (first) first = 0; else printf (" + "); printf("a33"); }
      printf(")*(");   first = 1;
      if (on[ 9]&2) { if (first) first = 0; else printf (" + "); printf("b11"); }
      if (on[10]&2) { if (first) first = 0; else printf (" + "); printf("b12"); }
      if (on[11]&2) { if (first) first = 0; else printf (" + "); printf("b13"); }
      if (on[12]&2) { if (first) first = 0; else printf (" + "); printf("b21"); }
      if (on[13]&2) { if (first) first = 0; else printf (" + "); printf("b22"); }
      if (on[14]&2) { if (first) first = 0; else printf (" + "); printf("b23"); }
      if (on[15]&2) { if (first) first = 0; else printf (" + "); printf("b31"); }
      if (on[16]&2) { if (first) first = 0; else printf (" + "); printf("b32"); }
      if (on[17]&2) { if (first) first = 0; else printf (" + "); printf("b33"); }
      printf(")*(");   first = 1;
      if (on[18]&2) { if (first) first = 0; else printf (" + "); printf("c11"); }
      if (on[19]&2) { if (first) first = 0; else printf (" + "); printf("c12"); }
      if (on[20]&2) { if (first) first = 0; else printf (" + "); printf("c13"); }
      if (on[21]&2) { if (first) first = 0; else printf (" + "); printf("c21"); }
      if (on[22]&2) { if (first) first = 0; else printf (" + "); printf("c22"); }
      if (on[23]&2) { if (first) first = 0; else printf (" + "); printf("c23"); }
      if (on[24]&2) { if (first) first = 0; else printf (" + "); printf("c31"); }
      if (on[25]&2) { if (first) first = 0; else printf (" + "); printf("c32"); }
      if (on[26]&2) { if (first) first = 0; else printf (" + "); printf("c33"); }
      printf(")\n");


      next_line:;
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
