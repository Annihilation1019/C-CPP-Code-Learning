#include <stdio.h>
void print(int x); // 函数声明，函数的声明和函数的定义可以分开写，但是函数的声明必须在函数的调用之前
int main()
{
    int a = 0;
    scanf("%d", &a);
    print(a);
    return 0;
}
void print(int x) // 函数定义
{
    if (x >= 9)
    {
        print(x / 10);
    }
    printf("%d ", x % 10);
}