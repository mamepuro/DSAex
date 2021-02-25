#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
 * 配列setが集合{3,7,11,15} を表現
 */
int set[] = {1,2,3,4,5,6,7,8,9,10};
int len = 10;

/*
 * set[] : 正の整数の集合
 * n :     対象とする要素数
 * sum :   部分和
 */
bool* subsetSum (int* set, int n, int sum) {
  bool* S  = (bool*)malloc(sizeof(bool) * len);
  bool** G = (bool**)malloc(sizeof(bool*) * n* (sum+1));
  for (int i = 0; i < len; i++)
  {
    S[i] = false;
  }
  
  for (int i = 0; i <= sum; i++)
  {
    G[i] = (bool*)malloc(sizeof(bool) * (sum + 1));
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= sum; j++)
    {
      G[i][j] = false;
    }
    
  }
  
  for (int k = 0; k < n; k++)
  {
    for (int s = 0; s <= sum; s++)
    {
      if(k == 0)
      {
        if(s == 0 || set[k] == s)
        {
          G[k][s] = true;
        }
      }
      else
      {
        if(G[k-1][s] || (set[k] <= s && G[k-1][s - set[k]]))
        {
          G[k][s] = true;
        }
      }
      
    }
    
  }
  //Sの計算
  int localSum = sum;
  int localN = n-1;
  while (localN >= 0)
  {
    if(localSum >= set[localN])
    {
      if(G[localN][localSum] && G[localN][localSum - set[localN]])
      {
        S[localN] = true;
        localSum = localSum - set[localN];
        localN = localN - 1;
      }
      else
      {
        localN = localN - 1;
      }
      
    }
    else
    {
      localN = localN - 1;
    }
    
  }
  for (int i = 0; i < n; i++)
  {
    if(S[i])
    {
      return S;
    }
  }

  return NULL;
}

int main(int argc, char* argv[]) {
  if (argc == 3) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    bool* S = subsetSum(set, n, k);
    if (S != NULL) {
      printf("部分集合");
      for (int j = 0; j < len; j++)
    if (S[j])
      printf("%d ", set[j]);
    } else
      printf("条件を満たす部分集合はない．\n");
  } else 
    fprintf(stderr, "Usage: subsetsum <n> <sum>\n");

  return 0;
}
