#include <stdio.h>
#include <stdlib.h>
#include "bst_advanced.h"

int main(void) {
  // Build an advanced binary search tree
  Node *root = NULL;
  root = insert_bst(root, 20);
  root = insert_bst(root, 10);
  root = insert_bst(root, 26);
  root = insert_bst(root, 14);
  root = insert_bst(root, 13);
  root = insert_bst(root,  5);

  printf("inorder: ");
  inorder(root);
  printf("\n");

  display(root);
  printf("\n");

  if (search_bst(root, 14)) {
    printf("Found!: 14\n");
  } else {
    printf("Not found!: 14\n");
  }
  if (search_bst(root, 7)) {
    printf("Found!: 7\n");
  } else {
    printf("Not found!: 7\n");
  }

  printf("Minimum value of this bst: %d\n", min_bst(root));

  root = delete_bst(root, 10);
  printf("Value 10 deleted\n");

  printf("inorder: ");
  inorder(root);
  printf("\n");

  display(root);
  printf("\n");

  delete_tree(root);

  return EXIT_SUCCESS;
}