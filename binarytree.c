#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

Queue *create_queue(int len)
{
    Queue *new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue ->length = len;
    new_queue ->count = 0;
    new_queue ->front = 0;
    new_queue ->rear = 0;
    new_queue ->buffer = (Node*)malloc(sizeof(Node) * len);
    return new_queue;
}

void enqueue(Queue *q, Node *d)
{
    q ->count += 1;
    if(q->count > q->length)
    {
        printf("QUEUE Overflow!!");
        exit(EXIT_FAILURE);
    }
    else
    {
        q ->buffer[q->rear] = *d;
        q ->rear = (q->rear+1) % (q->length);
    }
}

Node *dequeue(Queue *q)
{
    q->count = q->count - 1;
    if(q->count <0)
    {
        printf("QUEUE Underflow!");
        exit(EXIT_FAILURE);
    }
    Node *r = &(q->buffer[q->front]);
    q->front = (q->front +1) % (q->length);
    return r;
}

void delete_queue(Queue *q)
{
    free(q);
}

Node *create_tree(char *label, Node *left, Node *right)
{
    Node *root = (Node*)malloc(sizeof(Node));
    root->label = label;
    root->right = right;
    root->left = left;
    return root;
}

void preorder(Node *n)
{
    if(n == NULL)
    {
        return;
    }
    printf("%s ", n->label);
    preorder(n->left);
    preorder(n->right);
}

void inorder(Node *n)
{
    if(n == NULL)
    {
        return;
    }
    inorder(n->left);
    printf("%s ", n->label);
    inorder(n->right);
}

void postorder(Node *n)
{
    if(n == NULL)
    {
        return;
    }
    postorder(n->left);
    postorder(n->right);
    printf("%s ", n->label);
}

void display(Node *n)
{
    if(n==NULL)
    {
        printf("null");
    }
    printf("%s(",n->label);
    if(n->left == NULL)
    {
        printf("null");
    }
    else
    {
        display(n->left);
    }
    printf(",");
    if(n->right == NULL)
    {
        printf("null");
    }
    else
    {
        display(n->right);
    }
    printf(")");
}

void breadth_first_search(Node *n)
{
    Queue *tree_queue = create_queue(100);
    enqueue(tree_queue, n);
    while(tree_queue->count != 0)
    {
        Node *node = dequeue(tree_queue);
        printf("%s ", node->label);
        if(node->left != NULL)
        {
            enqueue(tree_queue, node->left);
        }
        if(node->right !=NULL)
        {
            enqueue(tree_queue, node->right);
        }
    }
    delete_queue(tree_queue);
}

int height(Node *n)
{
    if(n == NULL)
    {
        return 0;
    }
    int l_count = 1 + height(n->left);
    int r_count = 1 + height(n->right);
    if(l_count > r_count)
    {
        return l_count;
    }
    else
    {
        return r_count;
    }
}

void delete_tree(Node *n)
{
    if(n->left != NULL)
    {
        delete_tree(n->left);
    }
    if(n->right != NULL)
    {
        delete_tree(n->right);
    }
    free(n);
}