// 按递增顺序依次列出所有分母为40，分子小于40的最简分数。
#include <stdio.h>
int main()
{
    printf("1/40,");
    for (size_t i = 1; i < 41; i++)
    {
        if (40 % i != 0 && i % 2 != 0 && i % 2 != 0)
        {
            printf("%d/40,", i);
        }
    }
    return 0;
}