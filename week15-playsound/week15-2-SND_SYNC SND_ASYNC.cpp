#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("07074095.wav",NULL,SND_ASYNC);///ASYNC�������ݦP�B
    while(1){
        printf("�п�J�Ʀr: ");
        int n;
        scanf("%d",&n);
        if(n==1)PlaySound("do.wav",NULL,SND_ASYNC);
        if(n==2)PlaySound("re.wav",NULL,SND_ASYNC);
        if(n==3)PlaySound("mi.wav",NULL,SND_ASYNC);
    }
}
