#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", a >= b ? 1 : 0); // 常用于数值输出，如有函数指令还是用if，else
    return 0;
}