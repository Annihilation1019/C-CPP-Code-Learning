// 所给字符串正序和反序连接，形成新串并输出
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *p = NULL, *q = NULL;
    p = (char *)malloc(sizeof(char) * 100);
    q = (char *)malloc(sizeof(char) * 100);
    scanf("%s", p);
    for (size_t i = 0; i < strlen(p); i++)
    {
        *(q + i) = *(p + strlen(p) - i - 1);
    }
    printf("%s", strcat(p, q));
    free(p);
    free(q);
    p, q = NULL;
    return 0;
}