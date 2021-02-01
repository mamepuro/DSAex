#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "common.h"

int w[N][N] = {
  { 0, 5, 40, 10, M, 20},
  {10, 0, 20, M,  10, 10},
  { M, M,  0, M,  M, M},
  { M, M,  M, 0,  10, M},
  { M, M, M, M,  0, M},
  { M, M,  M, M,  M, 0}};
int d[N][N];
int parent[N][N];

void Floyd();
void display(char *, int *, int);
void display_shortest(int, int);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./main <node ID>\n");
    return 1;
  }
  int p = atoi(argv[1]);
  if (p < 0 || N <= p) {
    fprintf(stderr, "Node ID %d is out of range: [0, %d].\n", p, N);
    return 1;
  }
  Floyd();
  int dis[N];
  for(int i;i<N;i++)
  {
      dis[i] = d[p][i];
  }
  display("Result", dis, N);  // 結果表示
  for (int i = 0; i < N; i++)
  {
      display_shortest(p,i);
  }
  
  return 0;
}