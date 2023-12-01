// 给定 L, R，问 L ≤ x ≤ R 中有多少个数 x 满足存在整数 y,z 使得 x = y^2 − z^2。
#include <stdio.h>
int main()
{
    int L = 0, R = 0, j = 0;
    scanf("%d%d", &L, &R);
    for (size_t i = L; i <= R; i++)
    {
        if (i % 4 == 0 || i % 2 != 0)
        {
            j++;
        }
    }
    printf("%d", j);
    return 0;
}