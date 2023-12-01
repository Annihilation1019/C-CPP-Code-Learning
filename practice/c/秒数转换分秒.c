#include <stdio.h>
int main()
{
    int sec, min;
    printf("请输入秒数:");
    scanf("%d", &sec);
    min = sec / 60, sec %= 60;
    printf("\n%d分%d秒", min, sec);
    return 0;
}
