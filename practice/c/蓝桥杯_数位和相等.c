// 如果一个正整数转化成二进制与转换成八进制后所有数位的数字之和相等，则称为数位和相等的数。前几个数位和相等的正整数为 1, 8, 9, 64, ……请问第 23 个数位和相等的正整数是多少？
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int sum2(int i1);
int sum8(int i2);
int main()
{
    for (int i = 1; i < INT_MAX; i++)
    {
        if (sum8(i) == sum2(i))
        {
            printf("%9d\t", i);
        }
    }
    return 0;
}
int sum2(int i1)
{
    int a = 0, sum = 0;
    for (int j = 31; j >= 0; j--)
    {
        a = (i1 & 01);
        i1 >>= 1;
        sum += a;
    }
    return sum;
}
int sum8(int i2)
{
    int sum = 0, b = 0;
    for (int j = 31; j >= 0; j--)
    {
        if (i2 < 8)
        {
            sum += i2;
            break;
        }
        b = i2 % 8;
        i2 = i2 / 8;
        sum += b;
    }
    return sum;
}