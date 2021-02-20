#include <stdio.h>

int main() {
  int aux, N, v[100], s = 0, p_min, c[100], x[100], i, j;
  scanf("%d", & N);
  for (i = 0; i < N; i++) {
    scanf("%d", & x[i]);
  }
  for (i = 0; i < N; i++) {
    scanf("%d", & c[i]);
  }
  scanf("%d", & p_min);
  for (i = 0; i < N; i++) {
    s+= x[i] * c[i];
  }
  for (i = 0; i < N; i++) {
    v[i] = c[i] * (10 - x[i]);
  }
  for (i = 0; i < N - 1; i++) {
  for (j = i + 1; j < N; j++) {
    if (v[i] < v[j]) {
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
  }
  }
  }
  i = 0;
  while (i < N && p_min > s) {
    s+= v[i];
    i++;
  }
  if (p_min > s) {
    printf("-1\n");
  } else {printf("%d\n", i);}
  return 0;
}
