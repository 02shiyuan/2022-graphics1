#include <stdio.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;///宣告變數
int main()
{
    mp3.Load("bbc_animals--f_07063023.mp3");
    mp3.Play();
    printf("隨便等你輸入數字，程式就卡住囉: ");
    int n;
    scanf("%d",&n);
}
