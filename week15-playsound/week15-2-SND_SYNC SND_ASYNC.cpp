#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("07074095.wav",NULL,SND_ASYNC);///ASYNC為不等待同步
    while(1){
        printf("請輸入數字: ");
        int n;
        scanf("%d",&n);
        if(n==1)PlaySound("do.wav",NULL,SND_ASYNC);
        if(n==2)PlaySound("re.wav",NULL,SND_ASYNC);
        if(n==3)PlaySound("mi.wav",NULL,SND_ASYNC);
    }
}
