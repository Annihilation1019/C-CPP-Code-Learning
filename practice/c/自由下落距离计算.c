// 一球从M米高度自由下落，每次落地后返回原高度的一半，再落下。 它在第N次落地时反弹多高？ 保留两位小数
#include <stdio.h>
int main()
{
    float M, L = 0;
    int N;
    printf("请输入小球下落高度：");
    scanf("%f", &M);
    printf("请输入落地次数：");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        M = 0.5 * M;
    }
    printf("反弹高度为：%.2f", M);
    return 0;
}