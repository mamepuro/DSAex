#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "double_hashing.h"

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
    int ret = (d + count*g(dict, d))%(dict->B);
    return ret;
}

int g(DictOpenAddr *dict, int d)
{
    int ret = 1 + (d % (dict->B - 1));
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
        } while (count < dict->B);
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

void insert_hash_contiguous(DictOpenAddr *dict, int size, float alpha, int rand_max, int seed)
{
    int times = size * (float)alpha;
    //srand(seed);
    for(int i=0;i<times;i++)
    {
        int d = rand()%(rand_max);
        insert_hash(dict, d);
    }
}

double cal_average_time(DictOpenAddr *dict, int researchtime, int rand_max, int seed)
{
    double result = 0.0;
    double  sec;
    double nsec;
    double d_sec;
    double nsecs,nsece;
    struct timespec start_time, end_time;
    //srand(seed);
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    for (int i = 0; i < researchtime; i++)
    {
        int d = rand()%(rand_max);
        int a = search_hash(dict, d);
    }
    clock_gettime(CLOCK_MONOTONIC, &end_time);
        sec = end_time.tv_sec - start_time.tv_sec;
        nsecs = (double)start_time.tv_nsec*1e-9;
        nsece = (double)end_time.tv_nsec*1e-9;
        if(nsecs > nsece)
        {
            nsec = (1.0-nsecs)+ nsece;
            sec--;
        }
        else
        {
            nsec = nsece - nsecs;
        }

        d_sec = sec+nsec;
        result += d_sec;
    result = result / (double)researchtime;
    return result;
}