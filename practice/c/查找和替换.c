// 输入字符串，查找字符串中所有的a，并将其替换为b
#include <stdio.h>
#include <string.h>
void check(char *p);
int main()
{

    char a[100] = {0};
    fgets(a, 100, stdin);
    check(a);
    fputs(a, stdout);
    return 0;
}
void check(char *p)
{
    char *position;
    while (position = strchr(p, 'a'))
    {
        *position = 'b';
        p += (position - p) / sizeof(char);
    }
}