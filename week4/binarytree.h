#ifndef INCLUDE_GUARD_BINARYTREE_H
#define INCLUDE_GUARD_BINARYTREE_H

typedef struct node {
  char *label;
  struct node *left;
  struct node *right;
} Node;

typedef struct queue {
  Node *buffer;
  int length;
  int front;
  int rear;
  int count;
} Queue;


Node *create_tree(char *label, Node *left, Node *right);
void preorder(Node *n);
void inorder(Node *n);
void postorder(Node *n);
void display(Node *n);
void breadth_first_search(Node *n);
int height(Node *n);
void delete_tree(Node *n);

Queue *create_queue(int len);
void enqueue(Queue *q, Node *d);
Node *dequeue(Queue *q);
void delete_queue(Queue *q);

#endif  // INCLUDE_GUARD_BINARYTREE_H