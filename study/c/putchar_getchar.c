#include <stdio.h>
#define SPACE ' '//可以定义为字符常量，作为结束标志
int main()
{
    char ch;
    while ((ch = getchar()) != EOF)//结束标志为EOF,也可以设定为别的
    {
        if (ch == SPACE)
        {
            putchar(ch);
        }
        else
        {
            putchar(ch + 1);
        }
    }
    return 0;
}