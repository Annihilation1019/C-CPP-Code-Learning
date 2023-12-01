#include <stdio.h>
int main()
{
    char arr1[] = "abcdef";
    char arr2[] = "abcdef";
    char *p1 = "abcdef";
    char *p2 = "abcdef";
    if (arr1 == arr2)
    {
        printf("hehe\n");
    }
    else
    {
        printf("haha\n"); // 我们创建了两个数组，arr1和arr2，它们在内存中一定是有两块空间的，两个数组的数组名当然是两个不同的首元素地址了。即arr1不等于arr2的地址。所以打印“haha”。
    }
    return 0;
}
