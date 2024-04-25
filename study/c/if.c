#include <stdio.h>
int main()
{
    int a, b;
    printf("请输入两个随机数：");
    scanf("%d%d", &a, &b);
    if (a < b)
    {
        printf("最大的数是%d", b);
    }
    else // else与最近的if匹配,如果想让else与第一个if匹配，可以用大括号括起来
    {
        if (a == b)
        {
            printf("两个数相等");
        }
        else
        {
            printf("最大的数是%d", a);
        }
    }
    return 0;
}