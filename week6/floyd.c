#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // stdbool.hヘッダーファイルをインクルード
#include <limits.h>
#include "common.h"

extern int w[N][N];                     
extern int d[N][N];
extern int parent[N][N];
int top = 0;
int stack_size = 1000000;
int stack[1000000];
void push(int data, int s[])
{
    if(top > stack_size-1)
    {
        printf("STACK OVERFLOW!\n");
        return;
    }
    stack[top] = data;
    top++;
    return;
}

int pop(int s[])
{
    if(top == 0)
    {
        printf("STACK UNDERFLOW!\n");
        return -10000000;
    }
    top--;
    return stack[top];
}
void Floyd() {
  for (int i = 0; i < N; i++) 
  {
      for (int j = 0; j < N; j++)
      {
          d[i][j] = w[i][j];
          parent[i][j] = i;
      }
      
  }
  for (int k = 0; k < N; k++)
  {
      for(int i=0;i<N;i++)
      {
          for(int j=0;j<N;j++)
          {
              if(d[i][k] != M && d[k][j] != M)
              {
                    int can = d[i][k] + d[k][j];
                    if(can < d[i][j])
                    {
                        d[i][j] = can;
                        parent[i][j] = parent[k][j];
                    }
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
    int x;
     if(d[start][end] == M)
     {
         printf("There is no path.");
         return;
     }
     else
    {
         x = end;
         push(x, stack);
         while(x != start)
         {
             x = parent[start][x];
             push(x, stack);
         }
         printf("shortest_root(%d to %d):(START)", start, end);
         while (top != 0)
         {
             printf("-> %d  ", pop(stack));
         }
         printf("(END)\n");
         
    }
}