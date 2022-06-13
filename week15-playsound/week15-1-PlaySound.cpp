#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");
    PlaySound("07074095.wav",NULL,SND_SYNC);///檔案找不到時，會有錯誤的聲音
    printf("PlaySound()之後\n");
}

