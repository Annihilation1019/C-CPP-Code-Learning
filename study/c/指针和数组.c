#include <stdio.h>
#define SIZE 3
int main()
{
    int arr[SIZE] = {1, 2, 3};// 数组名是地址常量，如果改变数组名的值，就是改变数组的地址，这是不允许的
    printf("%d\n", arr == &arr[0]); // 数组名是该数组首元素的地址
    int *p1 = arr;
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("p+%d:%10p %10p\n", i, p1 + i, &arr[i]);//指针也可以用数组表示法访问数组元素，p[i]等价于*(p+i)
    }
    // 地址按字节编址，int类型占4个字节，在c中指针加1指的是增加一个储存单元，而不是加一个字节。对数组而言，这意味着把加1后的地址是下一个元素的地址，而不是下一个字节的地址。这是为什么必须声明指针所指向对象类型的原因之一，否则指针解引用无法返回正确的值。
    return 0;
}