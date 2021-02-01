#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {
  Queue *test_q = create_queue(4);

  enqueue(test_q, 1);
  enqueue(test_q, 2);
  enqueue(test_q, 3);
  printf("%d\n", dequeue(test_q));//以下、配列の末尾と先頭にまたがる
  enqueue(test_q, 4);
  printf("%d\n", dequeue(test_q));
  enqueue(test_q, 5);
  display(test_q);
  display(test_q);
  delete_queue(test_q);

  return EXIT_SUCCESS;
}