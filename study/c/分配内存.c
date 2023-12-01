#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
int *make_array(int elem, int val);
int main()
{
    // 动态数组
    int *p = (int *)malloc(ROWS * sizeof(int)); // malloc返回一个void*指针(通用指针)，需要强制类型转换
    if (p == NULL)
    {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE); // 退出程序，EXIT_FAILURE是stdlib.h中定义的宏，值为1，EXIT_SUCCESS为0，EXIT_SUCCESS表示成功，EXIT_FAILURE表示失败
    }
    else
    {
        for (size_t i = 0; i < ROWS; i++)
        {
            p[i] = i;
        }
        for (size_t i = 0; i < ROWS; i++)
        {
            printf("%2d", p[i]);
        }
    }
    free(p); // 释放内存，参数是malloc返回的指针，free将内存返回给系统，但不会改变指针的值，指针仍然指向原来的位置，但是这块内存已经不属于程序了，所以不能再使用这块内存
    printf("\n");

    int *p1 = make_array(ROWS, 10);
    for (size_t i = 0; i < ROWS; i++)
    {
        printf("%3d", p1[i]);
    }
    free(p1);

    // 动态内存分配和变长数组
    int n = 5;
    int m = 6;
    int ar2[n][m];                                        // 变长数组，可以省略形参名但不能省略列数
    int(*p2)[m] = (int(*)[m])malloc(n * m * sizeof(int)); // 动态分配内存，必须指定列数，p2[i]代表一个由m个int元素组成的数组，p2[i][j]代表一个int元素
    free(p2);

    
}

int *make_array(int elem, int val)
{
    int *p = (int *)malloc(elem * sizeof(int));
    if (p == NULL)
    {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE); // 退出程序，EXIT_FAILURE是stdlib.h中定义的宏，值为1，EXIT_SUCCESS为0，EXIT_SUCCESS表示成功，EXIT_FAILURE表示失败
    }
    else
    {
        for (size_t i = 0; i < elem; i++)
        {
            p[i] = val;
        }
    }
    return p;
}