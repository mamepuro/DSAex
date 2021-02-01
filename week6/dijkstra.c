#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // stdbool.hヘッダーファイルをインクルード
#include <limits.h>
#include "common.h"

extern int w[N][N];
extern bool S[N];
extern int Scount;                      // 頂点集合Sの要素数
extern int d[N];
extern int parent[N];

/**
 * 頂点集合 S に頂点 u を追加する．
 * @param u 追加する頂点
 * @param S 頂点集合
 * @return なし
 */
void add(int u, bool S[]) {
  // uの点を追加するには、S[u]=trueとすればよい
  S[u] = true;
  return;
}

/**
 * 頂点集合のうち S に追加されていない頂点があるかどうか確認する．
 * @return S に追加されていない頂点が存在すれば true，それ以外は false
 */
static bool remain() {
  // 関数を完成させる．
  for(int i=0;i<N; i++)
  {
      //S[i]==false ならtrueを返す
      if (!S[i])
      {
          return true;
      }
  }
  return false;
}

/**
 * p からの最短距離が確定していない頂点のうち，d[] が最小の頂点を
 * 返す．
 * @param なし
 * @return 未確定の d[] が最小の頂点
 */
int select_min() {
  // 関数を完成させる．
  int tmp_min = M;
  int tmp_min_location = -1;
  for(int i=0;i<N;i++)
  {
      if(d[i] < tmp_min && !S[i])
      {
          tmp_min = d[i];
          tmp_min_location = i;
      }
  }
  return tmp_min_location;
}

/**
 * 頂点 u から頂点 x に接続する辺が存在すれば true, それ以外は
 * false を返す.
 * @param u 頂点
 * @param x 頂点
 * @return 辺が存在すれば true, それ以外は false
 */
bool member(int u, int x) {
  // w[u][x] == M なら到達不可能の点（辺が存在しない）ためfalseを返す
  if(w[u][x] == M)
  {
      return false;
  }
  return true;
}

/**
 * ダイクストラ法で，頂点 p から各頂点への最短路の重みを計算する．
 * @param p 開始点
 * @return なし
 */
void dijkstra(int p) {
  add(p, S);
  for (int i = 0; i < N; i++) 
  {
      d[i] = w[p][i];
      parent[i] = p;
  }
  
    while(remain()) {
    int u = select_min();
    if (u == -1)
    {
        break;
    }
    else
    {
        add(u,S);
    }
    for (int x = 0; x < N; x++) {
        if (member(u, x)) {
        int k = d[u] + w[u][x];
        if (k < d[x])
        {
            d[x] = k;
            parent[x] = u;
        }
        }
    }
    }   
}


/**
 * 配列の中身を標準出力に表示．結果出力およびデバッグ用．
 * @param name ラベル（変数名など）
 * @param ary 配列
 * @return なし
 */
void display(char* name, int* ary, int length) {
  printf("%s: [", name);
  for (int i = 0; i < length; i++) {
    if (ary[i] == M)
      printf(" M");
    else
      printf(" %d", ary[i]);
  }
  printf(" ]\n");
}

void display_shortest(int start, int end)
{
    int tmp_pos = end;
    if(start == end)
    {
        return;
    }
    else
    {
        if(d[end] == M)
        {
            printf("no path\n");
            return;
        }
        printf("Shortest(NODE %d -> %d):", start, end);
        printf("(END)%d", end);
        while (parent[tmp_pos] != start)
        {
            printf("<- ");
            printf("%d ", parent[tmp_pos]);
            tmp_pos = parent[tmp_pos];
        }
        printf("<- %d(START)\n", start);
    }
    return;
}