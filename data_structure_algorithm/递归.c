// 输入n，计算1!+2!+3!+4!+...+n!
#include <stdio.h>
int i = 0, j = 0;
unsigned long long recursion(int n);
unsigned long long sum(int n);
int main()
{
    int n = 0;
    printf("请输入一个正整数：");
    scanf("%d", &n);
    printf("结果是：%llu", sum(n));
    printf("\n递归函数被调用了%d次，求和函数被调用了%d次", i, j);
}
unsigned long long recursion(int n)
{
    i++;
    if (n == 1) // 基线条件
    {
        return 1;
    }
    else // 递归条件
    {
        return recursion(n - 1) * n;
    }
}
unsigned long long sum(int n)
{
    j++;
    if (n == 1) // 基线条件
    {
        return 1;
    }
    else // 递归条件
    {
        return sum(n - 1) + recursion(n);
    }
}