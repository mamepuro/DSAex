#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * ナップサック問題の最適解を探索（動的計画法を用いない）
 * v: 価格の配列
 * w: 重さの配列
 * k: 対象とする荷物の数
 * i: ナップサックの容量
 */
int knapsack(int v[], int w[], int k, int i) {
  if (k == 0) return 0;
  if(i < w[k])
  {
    return knapsack(v, w, k-1, i);
  }
  else
  {
    int v1 = knapsack(v, w, k-1, i - w[k]) + v[k];

    int v2 = knapsack(v, w, k-1 , i);
    if(v1 > v2)
    {
      return v1;
    }
    else
    {
      return v2;
    }
  }
  
}

int main(int argc, char** argv) {
  /* 教科書：表 6.1の例
     v[1]〜v[4]：価格
     w[1]〜w[4]：重さ */
  int v[] = {0, 250, 380, 420, 520};
  int w[] = {0, 1, 2, 4, 3};


  // 引数処理
  if (argc == 3) {
    int k = atoi(argv[1]);
    int i = atoi(argv[2]);
    printf("%d\n", knapsack(v, w, k, i));
  } else if (argc == 2) {
    // 荷物をランダムに生成
    int n = atoi(argv[1]);
    int* v = (int*)malloc(sizeof(int) * (n + 1));
    int* w = (int*)malloc(sizeof(int) * (n + 1));
    // 乱数の初期化
    srand((unsigned int)time(NULL));
    for (int i = 1; i <= n; i++) {
      v[i] = rand() % 101;
      w[i] = rand() % 10 + 1;
    }
    // 実行時間を計測
    clock_t start_clock, end_clock;
    start_clock = clock();
    int i = knapsack(v, w, n, n * 5);
    end_clock = clock();
    printf("%d\n", i);
    printf("time: %f sec.\n", (double)(end_clock - start_clock) / CLOCKS_PER_SEC);
    free(v);
    free(w);
  } else {
    fprintf(stderr, "Usage: knapsack <k: no. of items> [<i: capacity>]\n");
    return 1;
  }
  return 0;
}