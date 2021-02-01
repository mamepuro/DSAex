#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define PAT_MAX 256     // パターンの最大の長さ
#define TEXT_MAX 1024 * 1024 * 10 // テキストの最大の長さ（10 MB）

bool isVerbose = false;     // 比較回数表示スイッチ
unsigned int Ncmp = 0;      // 比較回数のカウンタ

int readFile(char*, char*);
int kmp(char*, int, char*, int, int*);
int compnext(char*, int*);

int main(int argc, char** argv) {
  char pat[PAT_MAX];    // 検索パターン
  int next[PAT_MAX];
  char* text = (char *)malloc(TEXT_MAX * sizeof(char));
  int patlen = 0;
  int textlen = 0;

  // 引数処理・ファイル読み込み
  if (argc < 3 || 4 < argc) {
    fprintf(stderr, "Usage: ./main [-v] <text file> <pattern file>\n");
    return 1;
  }
  int i = 1;
  if (strcmp(argv[i], "-v") == 0) {
    isVerbose = true;
    i++;
  }
  textlen = readFile(argv[i++], text);
  patlen = readFile(argv[i], pat);

  // pat 末尾の改行コードを削除
  while (pat[patlen - 1] == '\r' || pat[patlen - 1] == '\n')
    pat[--patlen] = '\0';

  // 文字列照合・結果表示
  if (isVerbose) {
    printf("text size: %d\n", textlen);
    printf("pattern size: %d\n", patlen);
  }
  printf("Pattern found at %d.\n", kmp(text, textlen, pat, patlen, next));
  if (isVerbose)
    printf("# of comparisons: %d.\n", Ncmp);

  free(text);

  return 0;
}