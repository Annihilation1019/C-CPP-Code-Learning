#include <stdio.h>
int main()
{
    float x, y;
    printf("请输入x值：");
    scanf("%f", &x);
    if (x < 1)
    {
        y = x;
    }
    else if (1 <= x < 10)
    {
        y = 2 * x - 1;
    }
    else if (x >= 10)
    {
        y = 3 * x - 11;
    }
    printf("因变量y的值为:%.2f", y);
    return 0;
}