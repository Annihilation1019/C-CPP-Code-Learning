#include<stdio.h>
int main()
{
    int a[3][3] = {0};
    printf("请输入矩阵数值:");
    for (size_t i = 0; i < 3; i++)
    {
        int j = 0;
        for (size_t j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
        
    }
    printf("以下为两条对角线的和:");
    printf("%d %d", a[0][0] + a[1][1] + a[2][2], a[0][2] + a[1][1] + a[2][0]);
    return 0;
}