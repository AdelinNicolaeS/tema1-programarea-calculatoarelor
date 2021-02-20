#include <stdio.h>

int N_crescator(int N) {
  int aux, v[10], i, j, nr_cif = 0;
  while (N != 0) {
  v[nr_cif] = N % 10;
  N = N / 10;
  nr_cif++;
  }
  for (i = 0; i < nr_cif - 1; i++) {
    for (j = i + 1; j < nr_cif; j++) {
      if (v[i] > v[j]) {
       aux = v[i];
       v[i] = v[j];
       v[j] = aux;
  }
    }
  }
  for (i = 0; i < nr_cif; i ++) {
    N = N * 10 + v[i];
  }
  return N;
}
int N_descrescator(int N) {
  int aux, v[10], i, j, nr_cif = 0;
  while (N != 0) {
  v[nr_cif] = N % 10;
  N = N / 10;
  nr_cif++;
  }
  for (i = 0; i < nr_cif - 1; i++) {
     for (j = i + 1; j < nr_cif; j++) {
       if (v[i] < v[j]) {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }
  for (i = 0; i < nr_cif ; i++) {
  N = N * 10 + v[i];
  }
  return N;
}

int main() {
  int x, N, i, j, v[100], ok = 0;
  scanf("%d", & N);
  for (i = 0; ok == 0; i++) {
     N = N_descrescator(N) - N_crescator(N);
     v[i] = N;
     j = 0;
     while (j < i && ok == 0) {
        if (v[i] == v[j]) {
           ok = 1;
        }
        j++;
     }
     j--;
  }
  printf("%d\n", j);
  for (x = j; x < i - 1; x++) {
  printf("%d ", v[x]);
  }
}
