#include <stdio.h>
#include <stdlib.h>
#include "open_addressing.h"

DictOpenAddr *create_dict(int len)
{
    DictOpenAddr *new_dict_open_adder = (DictOpenAddr*)malloc(sizeof(DictOpenAddr));
    new_dict_open_adder->H = (DictData*)malloc(sizeof(DictData)*len);
    new_dict_open_adder->B = len;
    for(int i=0;i<new_dict_open_adder->B;i++)
    {
        new_dict_open_adder->H[i].state = EMPTY;
    }
    printf("Dictionary created!\n");
    return new_dict_open_adder;
}

int h(DictOpenAddr *dict, int d, int count)
{
    int ret = (d + count)%(dict->B);
    return ret;
}

void insert_hash(DictOpenAddr *dict, int d)
{
    if(search_hash(dict, d) != -1)
    {
        return;
    }
    else
    {
        int count = 0;
        int b = h(dict, d, count);
        int init_b = b;
        do
        {
            if(dict->H[b].state == EMPTY || dict->H[b].state == DELETED)
            {
                dict->H[b].name = d;
                dict->H[b].state = OCCUPIED;
                return;
            }
            count++;
            b = h(dict, d, count);
        } while (b != init_b);
        //all elements are "OCCUPIED"
        printf("ERROR!!: Dictionary is full!");
        exit(EXIT_FAILURE);
    }
    
}

int search_hash(DictOpenAddr *dict, int d)
{
    int count = 0;
    int b = h(dict, d, count); //b is index number
    int init_b = b;
    do
    {
        if(dict->H[b].state == OCCUPIED)
        {
            if(dict->H[b].name == d)
            {
                return b;
            }
        }
        else if (dict->H[b].state == EMPTY)
        {
            return -1;
        }
        count++;
        b = h(dict, d, count);
    } while (b != init_b);
    return -1;
}

void delete_hash(DictOpenAddr *dict, int d)
{
    int b = search_hash(dict, d);
    if(b == -1)
    {
        printf("ATTENTION!!: %d is not in this dictionary.", d);
        return;
    }
    dict->H[b].state = DELETED;
    return;
}

void display(DictOpenAddr *dict)
{
    for(int i = 0;i<dict->B;i++)
    {
        if(dict->H[i].state == OCCUPIED)
        {
            printf("%d ",dict->H[i].name);
        }
        else if (dict->H[i].state == EMPTY)
        {
            printf("e ");
        }
        else
        {
            printf("d ");
        }
    }
    printf("\n");
    return;
}

void delete_dict(DictOpenAddr *dict)
{
    free(dict);
    printf("Dictionary deleted!\n");
    return;
}