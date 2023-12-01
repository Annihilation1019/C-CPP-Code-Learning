/*小蓝有一个长度均为 n 且仅由数字字符 0 ∼ 9 组成的字符串，下标从 0 到 n − 1，你可以将其视作是一个具有 n 位的十进制数字 num，小蓝可以从 num 中选出一段连续的子串并将子串进行反转，最多反转一次。小蓝想要将选出的子串进行反转后再放入原位置处得到的新的数字 numnew 满足条件 numnew < num，请你帮他计算下一共有多少种不同的子串选择方案，只要两个子串在 num 中的位置不完全相同我们就视作是不同的方案。
注意，我们允许前导零的存在，即数字的最高位可以是 0 ，这是合法的。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    unsigned i, j, s = 0, p = 0;
    char str[5000];
    scanf("%4999s", str);
    for (i = 0; i < strlen(str); i++) // 枚举起点
    {
        for (j = i + 1; j < strlen(str); j++) // 枚举终点
        {
            while (i <= j) // 判断该子串是否满足题设
            {
                if (*(str + i) == *(str + j))
                {
                    i++, j--, p++;
                }
                else if (*(str + i) < *(str + j))
                {
                    break;
                }

                else
                {
                    s++; // 计数器加一
                    break;
                }
            }
            i -= p;
            j += p; // 恢复初始值
            p = 0;  // 初始化p
        }
    }
    printf("%u", s);
    return 0;
}
