#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void) {
  printf("指定したセル直後にセルの挿入ができることを確認する。\n");
  insert_cell_top(1);
  insert_cell(head,3);
  insert_cell(head,10);
  display();
  printf("\n");
  printf("先頭セルの削除ができることを確認する。\n");
  delete_cell_top();
  display();
  printf("\n");
  printf("指定したセルの直後を削除できることを確認する。\n");
  delete_cell(head);
  display();
  return EXIT_SUCCESS;
}