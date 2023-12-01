// 给出一百分制成绩，要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。 90分以及90分以上为A，80 - 89分为B，70 - 79分为C，60 - 69分为D，60分以下为E。
#include <stdio.h>
int main()
{
    int s;
    while (1)
    {
        printf("请输入成绩：");
        scanf("%d", &s);
        if (90 <= s && s <= 100)
        {
            putchar('A');
        }
        else if (80 <= s && s < 90)
        {
            putchar('B');
        }
        else if (70 <= s && s < 80)
        {
            putchar('C');
        }
        else if (60 <= s && s < 70)
        {
            putchar('D');
        }
        else if (0 <= s && s < 60)
        {
            putchar('E');
        }
        else
        {
            printf("输入错误，请重试\n");
            continue;
        }
        break;
    }
}