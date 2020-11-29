#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int main(void) {
  // Build a binary tree
  Node *f = create_tree("F", NULL, NULL);
  Node *i = create_tree("I", NULL, NULL);
  Node *d = create_tree("D", f, NULL);
  Node *g = create_tree("G", NULL, NULL);
  Node *a = create_tree("A", i, d);
  Node *l = create_tree("L", NULL, g);
  Node *c = create_tree("C", a, l);

  printf("preorder: ");
  preorder(c);
  printf("\n");

  printf("inorder: ");
  inorder(c);
  printf("\n");

  printf("postorder: ");
  postorder(c);
  printf("\n");

  printf("bfs: ");
  breadth_first_search(c);
  printf("\n");

  display(c);
  printf("\n");

  printf("height: %d\n", height(c));

  //delete_tree(c);

  return EXIT_SUCCESS;
}