// 3.数组转置：在主函数中定义一个n（1<=n<=6）维方阵，并从键盘读入数组元素；
// 编写函数transpose(a，n)实现数组a转置；在主函数中输出转置后的方阵。
// 例：输入    4
// 1   2   3   4                    输出     1   5   9   13
// 5   6   7   8                             2   6   10  14
// 9   10  11  12                            3   7   11  15
// 13  14  15  16                            4   8   12  16
#include <stdio.h>
void transpose(int x, int (*a)[x]);
int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n]; // 如果不支持VLA，可以写int (*a)[n] = (int (*)[n])malloc(sizeof(int) * n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]); // 对数组赋值
        }
    }
    transpose(n, a);
    return 0;
}

void transpose(int x, int a[][x])//int (*a)[x]也可以
{
    int y = x;
    int tem;
    for (int i = 0; i < y; i++)
    {
        for (int j = i + 1; j < x; j++) // 交换，只交换上半部分
        {
            tem = a[i][j];//(*(a+i))[j] = *(*(a+i)+j)
            a[i][j] = a[j][i];
            a[j][i] = tem;
        }
    }
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%3d", *(*(a + i) + j)); // 打印
        }
        printf("\n");
    }
}