// 求第n个斐波那契数列
#include <stdio.h>
int feb(int n);
int main()
{
    int n = 0, f = 0;
    scanf("%u", &n);
    printf("%d", feb(n));
    return 0;
}
int feb(int n)
{
    if (n > 2)
    {
        return feb(n - 1) + feb(n - 2);
    }
    else
    {
        return 1;
    }
}