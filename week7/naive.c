#include <stdlib.h>
#include <stdbool.h>

extern bool isVerbose;
extern int Ncmp;

bool cmp(char, char);

/**
 * 単純照合法による文字列照合．
 * @param text テキスト
 * @param pat 検索パターン
 * @return 照合に成功した位置．失敗した場合は -1．
 */
int naive(char* text, unsigned int textlen, char* pat, unsigned int patlen) {
    int text_point = 0;
    int pat_point = 0;
    //テキストの長さだけループさせる
    while(text_point < textlen)
    {
        //pat[pat_point]とtext[text_point]が一致しなければtextを進める（パターン一致調査中なら調査開始点+1の場所にずらす）
        //patは最初の文字に戻す
        if(!cmp(pat[pat_point], text[text_point]))
        {
            text_point = text_point - pat_point + 1;
            pat_point = 0;
        }
        else
        {
            if(pat_point == patlen - 1)
            {
                return text_point - patlen + 1;
            }

            else
            {
                text_point++;
                pat_point++;
            }
        }
    }
    //照合失敗
    return -1;
}