#include <stdio.h>
int main()
{
    char arr1[] = "abcdef";
    char arr2[] = "abcdef";
    char *p1 = "abcdef";
    char *p2 = "abcdef";
    if (p1 == p2) // p1,p2指向同一个地址，但是本身地址不同
    {
        printf("hehe\n");
    }
    else
    {
        printf("haha\n");
    }
    return 0;
} // 常量字符串不能被修改。两个字符串既然一模一样，又是常量字符串，各自又不能修改，没有必要再在内存中存两份。只需要拿去用，不能改它。为了在内存中节省空间，这两个“abcdef”只存了一份。（这一点非常重要）
