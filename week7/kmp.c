#include <stdlib.h>
#include <stdbool.h>

extern bool isVerbose;
extern int Ncmp;

bool cmp(char, char);
void compnext(char*, int*);

/**
 * 単純照合法による文字列照合．
 * @param text テキスト
 * @param pat 検索パターン
 * @return 照合に成功した位置．失敗した場合は -1．
 */
int kmp(char* text, unsigned int textlen, char* pat, unsigned int patlen, int* next) {
    int text_point = 0;
    int pat_point = 0;
    compnext(pat, next);
    //テキストの長さだけループさせる
    while(text_point < textlen)
    {
        while (pat_point >= 0 && !cmp(pat[pat_point], text[text_point]))
        {
            pat_point = next[pat_point] - 1;
        }
        if(pat_point != patlen - 1)
        {
            pat_point++;
            text_point++;
        }
        else
        {
            return text_point - patlen + 1;
        }
    }
    //照合失敗
    return -1;
}