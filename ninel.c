#include <stdio.h>

#include <stdlib.h>

int main() {
  long int S = 0;
  int x, i, nr = 0, y, z, xmax_impar = -1, N, xmin_par = 999999;
  double m_a = 0;
  fscanf(stdin, "%d", & N);
  fscanf(stdin, "%d", & x);
  if (N == 1 || N == 2) {
    xmax_impar = 0;
    xmin_par = 0;
    fprintf(stdout, "%ld\n", S);
    fprintf(stdout, "%.7f\n", m_a);
    fprintf(stdout, "%d\n", xmax_impar);
    fprintf(stdout, "%d", xmin_par);
  }
  fscanf(stdin, "%d", & y);
  for (i = 2; i < N; i++) {
    fscanf(stdin, "%d", & z);
    if (x < y && y > z) {
      if (i % 2 == 0) {
        if (y > xmax_impar) xmax_impar = y;
      } else if (y < xmin_par) { xmin_par = y; }
      S = S + y;
      nr++;
    }
    x = y;
    y = z;
  }
  fprintf(stdout, "%ld\n", S);
  m_a = (double) S / nr;
  fprintf(stdout, "%.7f\n", m_a);
  fprintf(stdout, "%d\n", xmax_impar);
  if (xmin_par == 999999) {
  xmin_par = -1;
  }
  fprintf(stdout, "%d\n", xmin_par);
}

