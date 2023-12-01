// 德国数学家哥德巴赫曾猜测：任何大于6的偶数都可以分解成两个素数（素数对）的和。但有些偶数可以分解成多种素数对的和，如： 10=3+7，10=5+5，即10可以分解成两种不同的素数对，输入任意的>6的正偶数(<32767)
#include <stdio.h>
int check(int n);     // 输入检查
int is_prinum(int x); // 质数判断
int main()
{
    unsigned n = 0, j = 0; // n为输入的数，j为素数对的个数
    do
    {
        scanf("%u", &n);
    } while (check(n));                 // 输入检查
    for (size_t i = 1; i <= n / 2; i++) // 从1开始遍历到n/2
    {
        if (is_prinum(i) && is_prinum(n - i)) // 如果i和n-i都是质数
        {
            j++; // 计数+1
        }
    }
    printf("%d", j); // 输出答案
    return 0;
}
int check(int n) // 输入检查
{
    if (n > 6 && n < 32767 && n % 2 == 0)
    {
        return 0;
    }
    else
    {
        printf("输入错误，请重试\n");
        return 1;
    }
}

int is_prinum(int x) // 质数判断
{
    int j = 0;
    if (x == 1)
    {
        return 0;
    }
    for (size_t i = 1; i <= x; i++) // 从2开始遍历到x-1
    {
        if (x % i != 0)
        {
            j++;
        }
    }
    if (j == x - 2) // 除了1和自身，没有其他因数
    {
        return 1;
    }
    else
    {
        return 0;
    }
}