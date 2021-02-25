#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * ナップサック問題の最適解を探索（動的計画法）
 * v: 価格の配列
 * w: 重さの配列
 * n: 対象とする荷物の数
 * C: ナップサックの容量
 */
bool* knapsack(int v[], int w[], int n, int C) {
  int k, i, v1;
  int** G = (int**)malloc(sizeof(int*) * (n + 1)*(C+1));
  bool** S = (bool**)malloc(sizeof(bool*) * (n + 1)*(C+1));
  bool* SS = (bool*)malloc(sizeof(bool) * (n + 1));

    for (int i=0;i<=n;i++) {
	    G[i] = (int*)malloc(sizeof(int)*(n+1));
        S[i] = (bool*)malloc(sizeof(bool)*(n+1));
    }
  // 動的計画法のプログラム（配列S[][]を計算）
    for (int i = 0; i <= n; i++)
    {
        SS[i] = false;
        for (int j = 0; j <= C; j++)
        {
            G[i][j] = 0;
            S[i][j] = false;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= C; i++)
        {
            if(i < w[k])
            {
                G[k][i] = G[k-1][i];
            }
            else
            {
                //k番目の荷物を使った
                int v1 = G[k-1][i-w[k]] + v[k];
                int v2 = G[k-1][i];
                if(v1 > v2)
                {
                    G[k][i] = v1;
                    S[k][i] = true;
                }
                else
                {
                    G[k][i] = v2;
                }
            }
         }
    }
    
  // 配列G[][]と配列S[][]から選択された荷物の集合SS[]を計算
  int weight = C;
  int localN = n;
  //重さが0になるかアイテムの数がゼロになるまでループする
  while(weight != 0 && localN != 0)
  {
      //S[localN][weight] ==trueすなわち、アイテムlocalN番目を重さ制限weightの時に持つなら
      if(S[localN][weight])
      {
          //最適解としてlocalN番目を登録する
          SS[localN] = true;
          //現在の重さ制限を、所持したアイテムの重さ分引く
          weight = weight - w[localN];
          localN = localN - 1;
      }
      //localN番目を持たない場合
      else
      {
          //localN番目の荷物を持たないので、localN-1番目の荷物を持つかどうかを調査する
          localN = localN - 1;
      }
      
  }
  return SS;
}

int main(int argc, char** argv) {
  /* 教科書：表 6.1の例
     v[1]〜v[4]：価格
     w[1]〜w[4]：重さ */
  int num = 4;
    // int v[] = {0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    // int w[] = {0, 1, 2, 8, 5, 6, 7, 9, 10, 3, 4};
//   int v[] = {0, 250, 380, 420, 520, 640, 750, 810, 920, 980, 1000};
//   int w[] = {0, 1, 2, 4, 3, 5,6,7,8,9,10};
   int v[] = {0, 250, 380, 420, 520};
   int w[] = {0, 1, 2, 4, 3};

  // 引数処理
  if (argc == 3) {
    int k = atoi(argv[1]);
    int i = atoi(argv[2]);
    bool* S = knapsack(v, w, k, i);  
    int total = 0;
    for (int k = 1; k <= num; k++) 
      if (S[k]) {
    total = total + v[k];
    printf("重さ %d 価値 %d\n", w[k], v[k]);
      }
    printf("合計価値 %d\n", total);
  } else {
    fprintf(stderr, "Usage: knapsackDP2 <k: no. of items> <i: capacity>\n");
    return 1;
  }
  return 0;
}