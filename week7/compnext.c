#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool cmp(char, char);
void display_next(int* next, int patlen)
{
    for (int i = 0; i < patlen; i++)
    {
        printf("%d ", next[i]);
    }
    printf("\n");
}
void compnext(char* pat, int* next)
{
    int patlen = strlen(pat);
    //nextを初期化する
    for(int i = 0;i<patlen;i++)
    {
        next[i] = 0;
    }
    //display_next(next, patlen);
    //２文字目から探索する
    int equalCount = 0;
    for(int j = 1;j<patlen;j++)
    {
        for(int i=0;i<patlen;i++)
        {
            //pat[i](ずらしたほうのpat)とずらさないほうのpat[i+j]が等しいか調べる
            //このfor文はパターン一致が進む限り回るので、一致した回数（すなわちi）だけずらさないpat[j]もずらす。よってi+j
            if(cmp(pat[i], pat[i+j]))
            {
                equalCount++;
            }
            else
            {
                break;
            }
        }
        if(next[j+equalCount] <equalCount+1)
        {
            next[j+equalCount] = equalCount + 1;
        }
        equalCount = 0;
    }
    display_next(next, patlen);
}