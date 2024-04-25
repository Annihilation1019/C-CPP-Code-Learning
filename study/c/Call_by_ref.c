#include <stdio.h>
int fun(int *a, int *b) // 传址可以不用返回值
{
    int c = *a + *b;
}
int main()
{
    int a = 0, b = 0, sum = 0;
    scanf("%d%d", &a, &b);
    sum = fun(&a, &b);
    printf("%d", sum);
    return 0;
}