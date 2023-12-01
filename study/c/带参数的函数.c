#include <stdio.h>
#include <stdlib.h>
void pound(); // 这是一个错误示例
int main()
{
    int times = 5;
    char ch = '!';
    float f = 6.0f;

    pound(times);
    pound(ch);     // char类型会被转换为int类型
    pound((int)f); // float类型会被自动升级为double类型，需要加强制转换

    return 0;
}
void pound(int n)
{
    while (n-- > 0)
    {
        printf("#");
    }
    printf("\n");
}