#include <stdio.h>
int sum(int[], int);              // 声明可以不写形参名,int []和int *等价,都表示arr是一个指向int的指针
int sump(int *, int *);           // 处理数组的函数实际上用的是指针作为形式参数,因为数组名是数组首元素的地址，所以可以用指针来处理数组,但可以选择是使用数组表示法还是指针表示法
int sump2(int arr[][4], int row); // 二维数组的行数必须指定,列数可以不指定,int arr3[][4]和int (*arr3)[4]等价,都表示arr3是一个指向含有4个int元素的数组的指针

int main()
{
    int arr0[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", sum(arr0, 10));
    printf("The size of arr0 is %zd\n", sizeof(arr0)); // 40,因为arr0是一个数组
    printf("The length of arr0 is %zd\n", sizeof(arr0) / sizeof(arr0[0]));
    int arr1[5] = {1, 2, 3, 4, 5};
    printf("%d\n", sum(arr1, 5));

    // 使用指针形参
    int arr2[5] = {1, 2, 3, 4, 5};
    printf("%d\n", sump(arr2, arr2 + 5)); // arr2+5是arr2的最后一个元素的下一个元素的地址

    // 用函数处理二维数组
    int arr3[3][4] = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6}};
    printf("%d\n", sump2(arr3, 3));
    printf("%d\n", sump2(arr3 + 1, 2)); // 只计算后两行
    int s;
    for (size_t i = 0; i < 3; i++)
    {
        s += sum(arr3[i], 4);
    }
    printf("%d\n", s); // 这种方法也可以计算二维数组的和

    return 0;
}

int sum(int arr[], int sz) // int *arr和int arr[]等价,都表示arr是一个指向int的指针
{
    int total = 0;
    for (int i = 0; i < sz; i++)
    {
        total += arr[i]; // arr[i]等价于*(arr+i)
    }
    return total;
}

int sump(int *begin, int *end)
{
    int total = 0;
    while (begin < end) // c保证在给数组分配空间时，指向数组后面第一个元素的指针是有效的
    {
        total += *begin++; // *begin++等价于*begin;begin++;
    }
    return total;
}

int sump2(int arr[][4], int row)
{
    int total = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total += arr[i][j]; // arr[i][j]等价于*(*(arr+i)+j)
        }
    }
    return total;
}