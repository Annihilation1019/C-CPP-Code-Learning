#include <stdio.h>
#include <string.h>
int main()
{
    char arr[] = "I love the earth";
    char *p = "I love China";
    strcpy(arr, p); // 将一个字符串指针拷贝到一个字符串数组中，不能反过来
    char *arr1 = "I love you";
    arr1 += 7;
    while (*arr1)
    {
        putchar(*(arr1++));
    }
    printf("\n%s", arr);
    return 0;
}