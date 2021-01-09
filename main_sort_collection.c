#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "sort_collection.h"

int GetRandom(int min, int max) {
  return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

double cal_average_time(int a[], int size)
{
    double result = 0.0;
    double  sec;
    double nsec;
    double d_sec;
    double nsecs,nsece;
    struct timespec start_time, end_time;
    //srand(seed);
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    heap_sort(a, size);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
        sec = end_time.tv_sec - start_time.tv_sec;
        nsecs = (double)start_time.tv_nsec*1e-9;
        nsece = (double)end_time.tv_nsec*1e-9;
        if(nsecs > nsece)
        {
            nsec = (1.0-nsecs)+ nsece;
            sec--;
        }
        else
        {
            nsec = nsece - nsecs;
        }

        d_sec = sec+nsec;
        result += d_sec;
    return result;
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    int numdata = atoi(argv[1]);  // set numdata with cmd. argument
    int *array = (int*)malloc(sizeof(int) * numdata);
    int i;
    printf("Enter %d integers\n", numdata);
    for (i = 0; i < numdata; i++) {
      scanf("%d", &array[i]);  // enter integers
    }
    radix_sort(array, numdata, 3);
    printf("sorting result\n");
    display(array, numdata);
    printf("# of comparisons: %lu\n", compare_count);
    free(array);
  } else {
    int numdata;
    for (numdata = 10000; numdata <= 100000; numdata += 10000) {  // numdata is 1000, 2000, ..., 10,000
      int *array = (int*)malloc(sizeof(int) * numdata);
      int i;
      for (i = 0; i < numdata; i++) {
        array[i] = numdata-i;  // random number from 0 to numdata * 10 - 1
      }
      double t =cal_average_time(array, numdata);
      printf("size: %d time:%lf", numdata, t);
      printf("%d %lu\n", numdata, compare_count);
      cmp_cnt_rest();
      free(array);
    }
  }

  return EXIT_SUCCESS;
}