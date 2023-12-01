// 在你的清单里，有n个梦想。但你的能力有限，你有s点能力评分。n个梦想分别有各自的能力值，你不能选择能力值超过s的梦想。在可选梦想中找到能力值尽可能大的梦想。
#include <stdio.h>
#include <limits.h>

int main()
{
    int n = 0, s = 0;
    scanf("%d%d", &n, &s); // 输入梦想个数和能力值
    int dream[n];
    int *p = dream;
    for (size_t i = 0; i < n; i++) // 输入n个梦想的对应所需能力值
    {
        scanf("%d", p++);
    }
    int max = INT_MIN; // 初始化max为最小值
    int sign = 0;
    p = dream;
    for (size_t i = 0; i < n; i++)
    {
        if (*(p + i) <= s) // 判断该梦想是否超过能力值
        {
            if (*(p + i) > max) // 找到限定范围的最大梦想值
            {
                max = *(p + i);
                sign = i;
            }
        }
    }
    if (max == INT_MIN) // 如果梦想所需能力值都超过自己能力值
    {
        printf("error");
    }
    else
    {
        printf("%d", *(p + sign));
    };
    return 0;
}
