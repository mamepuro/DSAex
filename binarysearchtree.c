#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"

//ラベルとしてdを持つノードを作成し、そのノードのポインタを返す。
Node *create_node(int d)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = d;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int min_bst(Node *root)
{
    int result = 0;
    if(root == NULL)
    {
        return -1;
    }
    if(root->left != NULL)
    {
        result = min_bst(root->left);
    }
    else
    {
        return root->value;
    }
    return result;
}

bool search_bst(Node *root, int d)
{
    Node *p = root;
    while(p != NULL)
    {
        if(p->value == d)
        {
            return true;
        }
        else if(p->value > d)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return false;
}

void insert_bst(Node **root, int d)
{
    if(*root == NULL)
    {
        *root = create_node(d);
        return;
    }
    //ラベルとしてdを持つノードがあるなら何もしない
    if(search_bst(*root, d))
    {
        return;
    }
    //ラベルとしてdを持たないノードがないので、再帰処理を用いて挿入すべき場所までノードを移動する。
    else
    {
        if((*root)->value > d)
        {
            insert_bst(&((*root)->left), d);
            return;
        }
        else
        {
            insert_bst(&((*root)->right), d);
            return;
        }
    } 
}

void delete_el(Node **current, Node **parent, char lr)
{
    //currentの中身が葉である場合
    if((*current)->left == NULL && (*current)->right == NULL)
    {
        //削除対象のノードが根である場合、根を削除する。
        if((*parent) == NULL)
        {
            (*current) = NULL;
        }
        else
        {      
            //削除対象のノードに親がありかつ削除対象が左の子である
            if(lr == 'L')
            {
                (*parent)->left = NULL;
            }
            //削除対象のノードに親がありかつ削除対象が右の子である
            else
            {
                (*parent)->right = NULL;
            }
            //currentポインタが指す内容を開放する
        }

        free((*current));
        return;
    }
    //子が一つである
    if((*current)->left == NULL || (*current)->right == NULL)
    {
        //削除対象が右の子を持つ
        if((*current)->left == NULL)
        {
            //削除対象が根である
            if((*parent) == NULL)
            {
                //右の子を削除対象のノードに移動する
                (*current) = (*current)->right;
            }
            else
            {
                //削除対象が左の子である
                if(lr == 'L')
                {
                    (*parent)->left = (*current)->right;
                }
                //削除対象が右の子である
                else
                {
                    (*parent)->right = (*current)->right;
                }
            }
        }
        //削除対象が左の子を持つ
        else
        {
            //削除対象が根である
            if((*parent) == NULL)
            {
                (*current) = (*current)->left;
            }
            else
            {
                //削除対象が左の子である
                if(lr == 'L')
                {
                    (*parent)->left = (*current)->left;
                }
                //削除対象が右の子である
                else
                {
                    (*parent)->right = (*current)->left;
                }
            }        
        }
        free((*current));
        return;
    }
}

void delete_bst(Node **root, int d)
{
    //どちらの子に進んだかを記憶する
    char lr;
    //rootがnullなら何もせず終了する
    if((*root) == NULL)
    {
        return;
    }
    //pの親のポインタを指すポインタ
    Node **parent;
    //親のポインタが指す内容は初期値NULLとする。
    *parent = NULL;
    while(*root != NULL)
    {
        //dを探索する
        if((*root)->value > d)
        {
            parent = root;
            lr = 'L';
            //rootはポインタのポインタであるから、アドレスを代入する
            root = &((*root)->left);
        }
        else if ((*root)->value < d)
        {
            parent = root;
            lr = 'R';
            root = &((*root)->right);
        }
        //dを発見
        else
        {
            //子が一つ以下である
            if((*root)->left == NULL || (*root)->right == NULL)
            {
                delete_el(root, parent, lr);
                return;
            }
            //子が２つある
            //右の子のポインタ
            Node **r = &((*root)->right);
            parent = root;
            lr = 'R';
            //削除対象のノードの右の部分木の最小値を探索する
            while ((*r)->left != NULL)
            {
                parent = r;
                r = &((*r)->left);
                lr = 'L';
            }
            //削除対処のノードのラベルとそのノードの右部分木の最小値を入れ替える
            (*root)->value = (*r)->value;
            (*r)->value = d;
            delete_el(r, parent, lr);
            return;
        }
    }
    return;
}


void inorder(Node *n)
{
    if(n == NULL)
    {
        return;
    }
    inorder(n->left);
    printf("%d ", n->value);
    inorder(n->right);
}

void display(Node *root)
{
    if(root == NULL)
    {
        printf("null");
    }
    printf("%d(", root->value);
    if(root->left == NULL)
    {
        printf("null");
    }
    else
    {
        display(root->left);
    }
    printf(",");
    if(root->right == NULL)
    {
        printf("null");
    }
    else
    {
        display(root->right);
    }
    printf(")");
}

void delete_tree(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left != NULL)
    {
        delete_tree(root->left);
    }
    if(root->right != NULL)
    {
        delete_tree(root->right);
    }
    free(root);
}