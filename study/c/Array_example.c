#include <stdio.h>
int main()
{
    // 首先创建数组并且初始化，如需创建只读数组，可以在创建数组时加上const关键字
    int arr[10] = {0};

    // 计算数组的元素个数
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", sz);

    // 下标起始位置
    int i = 0;

    for (i = 0; i < 10; i++) // 产生0-9的下标
    {
        arr[i] = i;
    }

    // 输出数组的内容

    for (i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("%d", sz);
    return 0;
}