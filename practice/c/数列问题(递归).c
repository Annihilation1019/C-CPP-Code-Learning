// 已知一个数列的前3个数为3，4，5，以后每个数为前3个数的和，编程序求此数列的第N项
#include <stdio.h>
int fun(int N) // 递归
{
    if (N > 3)
    {
        return fun(N - 1) + fun(N - 2) + fun(N - 3); // 递归调用
    }
    else if (N > 0 && N <= 3)
    {
        return N + 2;
    }
}
int main()
{
    int N = 0;
    scanf("%d", &N);
    printf("%d", fun(N));
    return 0;
}