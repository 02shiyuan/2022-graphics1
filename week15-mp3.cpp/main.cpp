#include <stdio.h>
#include "CMP3_MCI.h"///下載後放同一目錄使用
CMP3_MCI mp3;///宣告變數
int main()
{
    mp3.Load("bbc_animals--f_07063023.mp3");
    mp3.Play();
    printf("等待輸入數字: ");
    int N;///用輸入來卡住程式
    scanf("%d", &N);
}
