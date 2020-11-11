#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linear_probing.h"

int main(void) {
  int size = 10009;
  float alpha = 0;
  int rand_max = 500000;
  int inspect_times=10;
  int research_times =10000;
  double average[10];
  for(int j=0;j<11;j++)
  {
      DictOpenAddr *test_dict = create_dict(size);
      insert_hash_contiguous(test_dict, size, alpha, rand_max, 100+j);
      printf("alpha is %f\n", alpha);
      for (int i = 0; i < inspect_times; i++)
      {
            average[i] = cal_average_time(test_dict, research_times, rand_max, 300+j);
            printf("time[%d] is %.11lf\n", i,average[i]);
      }
      alpha += 0.1;
      delete_dict(test_dict);
  }
  return EXIT_SUCCESS;
}