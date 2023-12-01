#include <stdio.h>
int main()
{
    int c;
    c = getchar();
    while (c != EOF) // EOF的本质是-1，输入正确则不会返回-1即EOF，程序得以无限循环，将一个字符重复复制输出
    {
        putchar(c);
        c = getchar();
    }

    return 0;
}
