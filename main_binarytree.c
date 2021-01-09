#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int main(void) {
  // Build a binary tree
  Node *g = create_tree("G", NULL, NULL);
  Node *h = create_tree("H", NULL, NULL);
  Node *i = create_tree("I", NULL, NULL);
  Node *d = create_tree("D", NULL, NULL);
  Node *f = create_tree("F", h, g);
  Node *e = create_tree("E", NULL, i);
  Node *c = create_tree("C", d, e);
  Node *b = create_tree("B", f, NULL);
  Node *a = create_tree("A", c, b);
  
  printf("expected Output :preorder: A C D E I B F H G\n");
  printf("preorder: ");
  preorder(a);
  printf("\n");

  printf("expected Output :inorder: D C E I A H F G B\n");
  printf("inorder: ");
  inorder(a);
  printf("\n");

  printf("expected Output :postorder: D I E C H G F B A\n");
  printf("postorder: ");
  postorder(a);
  printf("\n");

  printf("expected Output :bfs: A C B D E F I H G\n");
  printf("bfs: ");
  breadth_first_search(a);
  printf("\n");

  printf("expected Output : A(C(D(null,null),E(null,I(null,null))),B(F(H(null,null),G(null,null)),null))\n");
  display(a);
  printf("\n");
  printf("expected Output : height: 4\n");
  printf("height: %d\n", height(a));

  delete_tree(c);
  printf("expected Output : A(null,B(F(H(null,null),G(null,null)),null))\n");
  display(a);
  return EXIT_SUCCESS;
}