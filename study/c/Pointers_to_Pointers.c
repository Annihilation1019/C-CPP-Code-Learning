#include <stdio.h>
int main()
{
    // 普通变量
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;

    // 一级指针
    int *p1 = &a1;
    int *p2 = &a2;
    int *p3 = &a3;

    // 二级指针
    int **s = &p1;
    printf("%d\n", **s);
    printf("%d\n", *p2);
    return 0;
}
