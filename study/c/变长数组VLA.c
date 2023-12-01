#include <stdio.h>
#include <stdlib.h>
int sum2d(int cols, int row, int (*arr)[cols]); // 处理任何行数列数的二维数组，可以省略形参名但不能省略列数
int main()
{
    // 在创建数组是，可以使用变量指定数组的维度
    int row = 3;
    int col = 4;
    int arr[row][col]; // 必须是auto变量
    int *parr = (int *)malloc(12 * sizeof(int));
    int ar[5][6] = {[2] = 1, [4][5] = 2};
    printf("%d\n", sum2d(5, 6, ar));
    int ar1[2][3] = {1, 2, 3, 4, 5, 6};
    printf("%d\n", sum2d(2, 3, ar1));

    // 复合字面量(就地构造一个指定类型（可以是 struct、union 或甚至数组类型）的未命名对象)：(int [2]){10, 20}是一个int[2]类型的复合字面量，可以用来初始化数组
    // 不能先创建后使用，因为它是一个临时对象，创建时同时使用
    int *p = (int[2]){10, 20};
    printf("%d\n", p[0]);
    // 作为实际参数传递给带有匹配形式参数的函数
    printf("%d\n", sum2d(2, 3, (int[2][3]){{1, 2, 3}, {4, 5, 6}})); // 不能省略列数
    return 0;
}

int sum2d(int cols, int row, int (*arr)[cols]) // 必须先声明行数和列数的形参，int arr[][cols]和int (*arr)[cols]等价
{
    int total = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            total += arr[i][j]; // arr[i][j]等价于*(*(arr+i)+j),指针表示法和数组表示法可以任意切换
        }
    }
    return total;
}