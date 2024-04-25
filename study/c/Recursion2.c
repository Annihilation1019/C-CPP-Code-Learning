// 求n的阶乘
#include <stdio.h>
int pro(int n);
int main()
{
    int a = 0, b = 0;
    scanf("%u", &b);
    a = pro(b);
    printf("%d", a);
    return 0;
}
int pro(int n)
{
    if (n > 1)
    {
        return n * pro(n - 1);
    }
}