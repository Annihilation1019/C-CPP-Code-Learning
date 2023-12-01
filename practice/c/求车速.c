// 一辆以固定速度行驶的汽车，司机在上午10点看到里程表上的读数是一个对称数(即这个数从左向右读和从右向左读是完全一样的)，为95859。两小时后里程表上出现了一个新的对称数。问该车的速度是多少？新的对称数是多少？
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
char *con(void) // 计算这个新的对称数,指针类型的函数
{
    char *s = NULL; // 用指针来存储这个新的对称数，并指向NULL
    s = (char *)malloc(sizeof(char) * 2);
    if (s == NULL)
    {
        printf("Failed to allocate memory\n");
    }
    for (size_t i = 95859; i < INT_MAX; i++)
    {
        itoa(i, s, 10); // 将数字转换成字符串
        if (*(s) == *(s + 4) && *(s + 1) == *(s + 3))
        {
            return s;
            break;
        }
    }
    free(s);
}
int main()
{
    float mile = 0, v = 0;
    char *s = con();
    mile = atoi(s);
    v = mile / 2;
    printf("%s ", s);
    printf("%.2f", v);
    s = NULL;
    return 0;
}