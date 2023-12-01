#include <stdio.h>
int main()
{
    int i = 0, sum = 0;
    while (i < 100) // 在表达式为假(或0)之前重复执行循环体语句部分。
    {
        sum = ++i + sum;
    }
    printf("%d", sum);
    return 0;
}