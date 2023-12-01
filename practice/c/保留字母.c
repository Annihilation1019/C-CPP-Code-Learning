// 编一个程序，输入一个字母字符串，将组成字符串的所有非大写字母的字符删除后输出。
// 例如，输入：abc123def4%&*5ghi6j7k，输出：abcdefghijk
/*参考资料：字符测试函数
int isalnum(int c)        该函数检查传递的字符是否是字母数字。
int isalpha(int c)        该函数是否传递的字符是字母。
int iscntrl(int c)        该函数是否传递的字符是控制字符。
int isdigit(int c)        该函数是否传递的字符是十进制数字。
int isgraph(int c)        该函数是否传递的字符的图形表示，使用的语言环境。
int islower(int c)        该函数检查传递的字符是否是小写字母。
int isprint(int c)        该函数检查传递的字符是否是可打印的。
int ispunct(int c)        该函数检查传递的字符是否是标点符号。
int isspace(int c)        该函数检查传递的字符是否是空白（空格）。
int isupper(int c)        该函数检查传递的字符是否是大写字母。
int isxdigit(int c)       该函数检查传递的字符是否是十六进制数字。
tolower(int c)            如果参数是大写字符，该函数返回小写字符，否则，返回原始参数
toupper(int c)            如果参数是小写字符，该函数返回小写字符，否则，返回原始参数  */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *p = NULL;                         // 指针初始化
    p = (char *)malloc(sizeof(char) * 100); // 分配内存
    scanf("%s", p);                         // 输入字符串，含大小写字母
    for (size_t i = 0; i < strlen(p); i++)  // 遍历字符串
    {
        if (islower(*(p + i)))
        {
            printf("%c", *(p + i)); // 输出小写字母
        }
    }
    free(p);  // 释放内存
    p = NULL; // 指针置空
    return 0;
}