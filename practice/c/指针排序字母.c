// 输入一串字母，按字母表顺序重新排序后输出
#include <stdio.h>
#include <string.h>
#define LEN 20
int main()
{
    char str[LEN] = {0};
    char *pstr[LEN];
    char *temp;
    char *find;
    fgets(str, LEN, stdin);
    while ((find = strchr(str, '\n')) != NULL)
    {
        *find = '\0';
    }
    for (size_t i = 0; i < strlen(str); i++) // 令指针指向数组
    {
        pstr[i] = str + i;
    }
    for (size_t i = 0; i < strlen(str); i++) // 排序算法，依次把每个元素与首元素比较
    {
        for (size_t j = i + 1; j < strlen(str); j++)
        {
            if (strcmp(pstr[i], pstr[j]) > 0)
            {
                temp = pstr[i];
                pstr[i] = pstr[j];
                pstr[j] = temp;
            }
        }
    }
    for (size_t i = 0; i < strlen(str); i++)
    {
        printf("%c", *pstr[i]);
    }
    return 0;
}