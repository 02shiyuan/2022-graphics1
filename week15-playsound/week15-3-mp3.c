#include <stdio.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;///�ŧi�ܼ�
int main()
{
    mp3.Load("bbc_animals--f_07063023.mp3");
    mp3.Play();
    printf("�H�K���A��J�Ʀr�A�{���N�d���o: ");
    int n;
    scanf("%d",&n);
}
