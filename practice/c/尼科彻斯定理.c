// 验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。
#include <stdio.h>
#include <math.h>
#include <limits.h>
int main()
{
    int m = 0, sum = 0, n = 0, j = 0;
    scanf("%d", &m);
    sum = pow(m, 3);
    printf("%d*%d*%d=%d=", m, m, m, sum);
    n = pow(m, 2) - m + 1;
    j = n;
    printf("%d", j);
    while (n != sum)
    {
        j += 2;
        n = n + j;
        printf("+%d", j);
    }
    return 0;
}