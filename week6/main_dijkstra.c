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

bool S[N];
int Scount = 0;                      // 頂点集合Sの要素数
int d[N];
int parent[N];

void add(int, bool[]);
bool remain();
int dijkstra(int);
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
  for (int i = 0; i < N; i++)
  {
      S[i] = false;
  }
  dijkstra(p);              // ダイクストラ法による最短路の計算
  display("Result", d, N);  // 結果表示
  for (int i = 0; i < N; i++)
  {
      display_shortest(p,i);
      //printf("%d",parent[i]);
  }
  
  return 0;
}