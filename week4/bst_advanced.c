#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst_advanced.h"

Node *create_node(int d)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = d;
    new_node->height = 1;
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

int get_height(Node *root) {
  if (root == NULL) return 0;
  else              return root->height;
}

int reset_height(Node *root) {
  int lh = get_height(root->left);
  int rh = get_height(root->right);
  return 1 + (lh > rh ? lh : rh);
}

Node *insert_bst(Node *root, int d) 
{
    if(root == NULL)
    {
        root = create_node(d);
        return root;
    }
    //ラベルとしてdを持つノードがあるなら何もしない
    if(search_bst(root, d))
    {
        return root;
    }
    //ラベルとしてdを持たないノードがないので、再帰処理を用いて挿入すべき場所までノードを移動する。
    else
    {
        if(root->value > d)
        {
            root->left = insert_bst(root->left, d);
            root->height = reset_height(root);
            return root;
        }
        else
        {
            root->right = insert_bst(root->right, d);
            root->height = reset_height(root);
            return root;
        }
    } 
}

Node *delete_min_bst(Node *root) 
{
    //rootがNULLの場合は何もしない
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        //左に子がある場合は左のノードへ進む
        if(root->left != NULL)
        {
            root->left = delete_min_bst(root->left);
            //高さを更新する
            root->height = reset_height(root);
            return root;
        }
        //最小値を持つノード発見
        else
        {
            //削除対象が右の子を持つ場合
            /*なお、削除対象は左の子を持ち得ない（上のif文で左の子を持つ場合は除外される）*/
            if(root->right != NULL)
            {
                //右の子を削除対象のノードがあった場所に移動し、削除対象のノードを開放する
                Node *result = root->right;
                free(root);
                return result;
            }
            //削除対象が子を持たない
            else
            {
                //削除対象を開放し、NULLを返す
                free(root);
                return NULL;
            }
        }
    }
}

Node *delete_bst(Node *root, int d) 
{
    //rootがNULLなら何もしない
    if(root == NULL)
    {
        printf("Root is NULL!");
        return NULL;
    }
    //dを探索する
    if(root->value > d)
    {
        //左の子が存在しない（dがこの木に存在しない）
        if(root->left ==NULL)
        {
            printf("DATA %d is not in this tree!", d);
            return root;
        }
        //左のノードに進む
        root->left = delete_bst(root->left, d);
        root->height = reset_height(root);
        return root;
    }
    else if(root->value < d)
    {
        //右の子が存在しない（dがこの木に存在しない）
        if(root->right ==NULL)
        {
            printf("DATA %d is not in this tree!", d);
            return root;
        }
        //右のノードに進む
        root->right = delete_bst(root->right, d);
        root->height = reset_height(root);
        return root;
    }
    //dを発見
    else
    {
        //削除対象が右と左の子を持つ
        if(root->left != NULL && root->right != NULL)
        {
            //削除対象のノードのラベルを削除対象の右部分木の最小値に変更する
            root->value = min_bst(root->right);
            //削除対象の右部分木を、その部分木中の最小値を削除したものに変更する
            root->right = delete_min_bst(root->right);
            root->height = reset_height(root);
            return root;
        }
        //削除対象が右の子のみを持つ
        else if (root->right != NULL && root->left == NULL)
        {
            Node *reslut = root->right;
            free(root);
            return reslut;
        }
        //削除対象が左の子のみを持つ
        else if (root->left != NULL && root->right == NULL)
        {
            Node *reslut = root->left;
            free(root);
            return reslut;
        }
        //削除対象が葉である
        else
        {
            //メモリを開放しNULLを返す。
            free(root);
            return NULL;
        }
        
    }
    
}

void inorder(Node *root) 
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void display(Node *root) 
{
    if(root == NULL)
    {
        printf("null");
    }
    printf("%d#%d(", root->value, root->height);
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