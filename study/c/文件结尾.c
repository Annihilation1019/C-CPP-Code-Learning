#include<stdio.h>
int main()
{
    int ch;
    while ((ch = getchar()) != EOF)//EOF是文件结束符,在stdio.h中定义为-1,即EOF=-1,所以ch=getchar()的返回值是-1时,循环结束
    {
        putchar(ch);
    }
    return 0;
    //用ctrl+z结束输入,文件末尾一般都有嵌入的ctrl+z,所以输入ctrl+z就相当于输入了EOF
}