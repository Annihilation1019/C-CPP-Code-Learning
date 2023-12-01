#include <stdio.h>
int main()
{ // 能打印出后面的，是系统并没屏蔽用户程序继续访问数组空间后面的东西，但由于不可控就可能有各种情况了
    int a[10] = {0};
    for (size_t i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}