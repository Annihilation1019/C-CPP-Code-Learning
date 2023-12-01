// 打印出所有"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该本身。 例如：153是一个水仙花数，因为153=1^3+5^3+3^3。
#include <stdio.h>
#include <math.h>
int main()
{
    int i, a;
    for (i = 100; i <= 999; i++)
    {
        if (i == pow((i / 100), 3) + pow(((i % 100) / 10), 3) + pow((i % 10), 3))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}