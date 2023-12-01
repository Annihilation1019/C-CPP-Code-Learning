#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *p = NULL; // 用于存储二进制字符串
    p = (char *)malloc(sizeof(char) * 10);
    scanf("%s", p);
    printf("%d", strtoll(p, NULL, 2)); // 二进制转十进制
    free(p);
    p = NULL;
    return 0;
}