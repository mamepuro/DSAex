#include <stdio.h>
#include <stdlib.h>
#include "sort_collection.h"
#include <stdbool.h>
#include <math.h>

unsigned long compare_count = 0;

void cmp_cnt_rest(void) {
  compare_count = 0;
}

int compare(int ldata, int rdata, bool isDebug) {
  compare_count++;
  if      (ldata  < rdata) 
    {
        //デバックモードがtrueなら実行結果と累計の比較回数を表示する
        if(isDebug)
        {
            printf("rdata(%d) is bigger! (than ldata(%d))\n", rdata, ldata);
            printf("Now compare count is %lu\n", compare_count);
        }
        return -1;
    }
  else if (ldata == rdata) 
    {
        if(isDebug)
        {
            printf("rdata(%d) = ldata(%d)\n", rdata, ldata);
            printf("Now compare count is %lu\n", compare_count);
        }
        return  0;
    }
  else
    {
        if(isDebug)
        {
            printf("ldata(%d) is bigger! (than rdata(%d))\n", ldata, rdata);
            printf("Now compare count is %lu\n", compare_count);
        }
        return  1;
    }                     
}

void swap(int a[], int lidx, int ridx, bool isDebug) {
    //デバックモードがtrueならスワップ内容を表示する
    if(isDebug)
    {
        printf("Swapping %d for %d.\n", a[lidx], a[ridx]);
    }
  int temp = a[lidx];
  a[lidx] = a[ridx];
  a[ridx] = temp;
}

void display(int a[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void selection_sort(int a[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    int min = i;
    for (j = i + 1; j < n; j++) {
      if (compare(a[j], a[min],true) == -1) {
        min = j;
      }
    }
    swap(a, i, min,true);
  }
}

// Insertion sort
/**************************************/
void insertion_sort(int a[], int n) 
{
    for(int i=1;i<n;i++)
    {
        int insertion_data = a[i];
        int j = i-1;
        while(j >= 0 && compare(a[j],insertion_data, true) == 1)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = insertion_data;
    }
}

// Functions for Heap sort
/**************************************/
void sift_down(int a[], int i, int n) {
    //ノードiに子が存在しない場合何もしない
    if(2*i + 1 > n-1)
    {
        return;
    }
    else
    {
        //左の子しか存在しない場合
        if(2*i+2 > n-1)
        {
            //ノードiより左の子が大きい場合
            if(compare(a[2*i+1], a[i], false) == 1)
            {
                //データを交換する
                swap(a, 2*i+1, i, false);
                //交換先の右の子について再帰呼び出しでさらにshift_downを適用する
                sift_down(a, 2*i+1, n);
            }
        }
        //左右の子が存在する
        else
        {
            //左の子のほうが大きいか右の子以上である
            if(compare(a[2*i+1], a[2*i+2], false) >= 0)
            {
                //ノードiの左の子のほうがノードiより大きい
                if(compare(a[2*i+1], a[i], false) == 1)
                {
                    swap(a, 2*i+1, i, false);
                    //再帰呼び出しでさらに子に対して探索する
                    sift_down(a, 2*i+1, n);
                }
            }
            //右の子のほうが大きい
            else
            {
                //ノードiの右の子のほうがノードiより大きい
                if(compare(a[2*i+2], a[i], false) == 1)
                {
                    swap(a, 2*i+2, i, false);
                    //再帰呼び出しでさらに子に対して探索する
                    sift_down(a, 2*i+2, n);
                }
            }
        }
        //ノードiはノードiのどの子よりも大きいので操作を終了する
        return;
    }
    
}

void build_heap (int a[], int n) {
    int nodeI = (int)floor(n/2) -1;
    for(int i = nodeI; i>= 0; i--)
    {
        sift_down(a, i, n);
    }
    printf("Heap builded successfully!!\n");
}

void heap_sort (int a[], int n) {
    build_heap(a, n);
    for(int i = n -1; i > 0; i--)
    {
        swap(a, i, 0, false);
        sift_down(a, 0, i);
    }
}

// Functions for Quick sort
/**************************************/
int partition(int a[], int pivot, int left, int right) {
    swap(a, right, pivot, false);
    int l = left;
    int r = right - 1;
    while (1)
    {
        //while a[l] < a[right]
        while (compare(a[l], a[right], false) == -1)
        {
            l = l + 1;
        }
        //while a[r] >= a[right]
        while (l <= r && compare(a[r], a[right], false) >= 0)
        {
            r = r - 1;
        }
        if(l < r)
        {
            swap(a, l, r, false);
        }
        else
        {
            break;
        }
    }
    swap(a, l, right, false);
    return l;
}

void quick_sort(int a[], int left, int right) {
    if(left < right)
    {
        int pivot = right;
        int p = partition(a, pivot, left, right);
        quick_sort(a, left, p-1);
        quick_sort(a, p+1, right);
    }
}

void q_sort(int a[], int n) {
  quick_sort(a, 0, n-1);
}

Queue *create_queue(int len)
{
    Queue *new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue ->length = len;
    new_queue ->count = 0;
    new_queue ->front = 0;
    new_queue ->rear = 0;
    new_queue ->buffer = (int*)malloc(sizeof(int) * len);
    return new_queue;
}

void enqueue(Queue *q, int d)
{
    q ->count += 1;
    if(q->count > q->length)
    {
        printf("QUEUE Overflow!!");
        exit(EXIT_FAILURE);
    }
    else
    {
        q ->buffer[q->rear] = d;
        q ->rear = (q->rear+1) % (q->length);
    }
}

int dequeue(Queue *q)
{
    q->count = q->count - 1;
    if(q->count <0)
    {
        printf("QUEUE Underflow!");
        exit(EXIT_FAILURE);
    }
    int r = q->buffer[q->front];
    q->front = (q->front +1) % (q->length);
    return r;
}
void radix_sort(int a[], int n, int k){
    Queue *q[10];
    //作業量のキュー、作業用配列b[]に格納するデータの順序を配列a[]内のデータの順と対応させるために利用する
    Queue *qq[10];
    //作業量の配列を宣言サイズは1000000とする。すなわち、radix_sortの引数で与えられた配列のサイズが1000000を超えることを想定しない
    int b[1000000];
    if(n > 1000000)
    {
        printf("ERROR!:array size is too big !!\n");
        return;
    }
    for(int i =0;i<10;i++)
    {
        q[i] = create_queue(n);
        qq[i] = create_queue(n);
    }
    for(int i =1;i<k+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == 1)
            {
                b[j] = a[j];
            }
            int num = b[j] % 10;
            //bにはi桁目を消去した数を代入する
            b[j] = (b[j] - num) / 10;
            enqueue(q[num], a[j]);
            enqueue(qq[num], b[j]);
        }
        //配列a[]の内容を第i桁目の値によってソートしたものに変える
        for(int l = 0, m = 0; m < 10;m++)
        {
            while (q[m]->count > 0)
            {
                a[l] = dequeue(q[m]);
                b[l] = dequeue(qq[m]);
                l = l+1;
            }
        }
        display(a, n);
    }
}