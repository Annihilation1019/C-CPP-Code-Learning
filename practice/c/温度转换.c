#include <stdio.h>
int main()
{
    float F, c;
    printf("请输入华氏温度：");
    scanf("%f", &F);
    c = 5 / 9 * (F - 32);
    printf("摄氏度为%.2f℃", c);
    return 0;
}