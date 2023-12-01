// 不断缩小问题规模，直到问题足够简单，可以直接求解
#include <stdio.h>
int D_C(int *arr, int i)
{
    if (i < 0) // 基线条件，数组为空
    {
        return 0;
    }
    else // 递归条件
    {
        return *(arr + i) + D_C(arr, i - 1);
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d", D_C(arr, 8));
}