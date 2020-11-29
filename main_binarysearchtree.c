#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"

int main(void) {
  // Build a binary search tree
  Node *root = NULL;
  insert_bst(&root, 20);
  insert_bst(&root, 10);
  insert_bst(&root, 26);
  insert_bst(&root, 14);
  insert_bst(&root, 13);
  insert_bst(&root,  5);

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

   delete_bst(&root, 10);
   printf("Value 10 deleted\n");

  printf("inorder: ");
  inorder(root);
  printf("\n");

  display(root);
  printf("\n");

  delete_tree(root);

  return EXIT_SUCCESS;
}