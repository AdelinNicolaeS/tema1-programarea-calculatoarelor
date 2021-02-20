#include <stdio.h>

int verificare_linie(int i, int b[100][100], int a[200][100], int M) {
  int nr = 0, alfa, l = 0, ok = 0, c, v[100];
  for (c = 0; c < M; c++) {
    if (b[i][c] == 1) {
      if (ok == 0) {
        l = 1;
        nr++;
        ok = 1;
      } else if (ok == 1) {l++;}
    } else if (b[i][c] == 0 && ok == 1) {
      ok = 0;
      v[nr] = l;
      l = 0;
    }
  }
  if (b[i][M-1] == 1) {
    if (ok == 1) {
      v[nr] = l;
    }
    if (ok == 0) {
      nr++;
      v[nr] = 1;
    }
  }
  v[0] = nr;
  alfa = 1;
  for (c = 0; c <= nr; c++) {
    if (v[c] != a[i][c]) {
      alfa = 0;
    }
  }
  return alfa;
}
int verificare_coloana(int j, int b[100][100], int a[200][100], int N) {
  int nr = 0, alfa, l = 0, ok = 0, c, v[100];
  for (c = 0; c < N; c++) {
    if (b[c][j] == 1) {
      if (ok == 0) {
        l = 1;
        nr++;
        ok = 1;
      } else if (ok == 1) {l++;}
    } else if (b[c][j] == 0 && ok == 1) {
      ok = 0;
      v[nr] = l;
      l = 0;
    }
  }
  if (b[N-1][j] == 1) {
    if (ok == 1) {
      v[nr] = l;
    }
    if (ok == 0) {
      nr++;
      v[nr] = 1;
    }
  }
  v[0] = nr;
  alfa = 1;
  for (c = 0; c <= nr; c++) {
    if (v[c] != a[j + N][c]) {
      alfa = 0;
    }
  }
  return alfa;
}
int main() {
  int x, y, T, N, M, a[200][100], b[100][100], p = 1, i, j;
  scanf("%d", & T);
  for (y = 0; y < T; y++) {
    p = 1;
    scanf("%d %d", & N, & M);
  for (i = 0; i < N + M; i++) {
    scanf("%d", & a[i][0]);
    x = a[i][0];
    j = 0;
    while (x != 0) {
      j++;
      scanf("%d", & a[i][j]);
      x--;
    }
  }
    for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      scanf("%d", & b[i][j]);
    }
  }
  for (i = 0; i < N; i++) {
    p = p * verificare_linie(i, b, a, M);
  }
  for (j = 0; j < M; j++) {
    p = p * verificare_coloana(j, b, a, N);
  }
  if (p == 0) {
    printf("Eroare\n");
  } else {printf("Corect\n");}
  }
}
