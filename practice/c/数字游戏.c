// 小 K 同学向小 P 同学发送了一个长度为 8 的 01 字符串来玩数字游戏，小 P 同学想要知道字符串中究竟有多少个 1。 注意：01 字符串为每一个字符是 0 或者 1 的字符串，如“101”（不含双引号）为一个长度为 3 的 01 字符串。
#include <stdio.h>
int main()
{
    char a[8] = {0};
    char *p = a;
    int si = 0;
    scanf("%7s", a);
    for (size_t i = 0; i < 7; i++)
    {
        if (*(p + i) == '1')
        {
            si += 1;
        }
    }
    printf("%d", si);
    return 0;
}