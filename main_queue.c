#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {
  Queue *test_q = create_queue(10);

  enqueue(test_q, 1);
  enqueue(test_q, 2);
  display(test_q);

  printf("%d\n", dequeue(test_q));
  printf("%d\n", dequeue(test_q));

  //delete_queue(test_q);

  return EXIT_SUCCESS;
}