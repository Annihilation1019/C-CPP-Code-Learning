// 计算器
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int check(char *s); // 检查输入内容是否正确
void calculate(char *s);//计算
int main()
{
    char *s = NULL;
    s = (char *)calloc(50, sizeof(char *));
    printf("请输入算式：");
sign:
    scanf("%s", s); // 输入算式以字符串形式暂存
    if (check(s))
    {
        goto sign;
    }
    else
    {
        printf("%s=", s);
        calculate(s);
    }
    free(s);
    s = NULL;
    return 0;
}

int check(char *s)
{
    for (size_t i = 0; i < strlen(s); i++)
    {
        if (isdigit(*(s + i)) || ispunct(*(s + i)))
        {
            continue;
        }
        else
        {
            printf("非法输入，请重试\n");
            return 1;
            break;
        }
    }
    return 0;
}
void calculate(char *s)
{
    
}