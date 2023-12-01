// 时间复杂度O(n*n) 空间复杂度O(1)
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
void input_arr(int size, int *arr);
void Selection_sort(int size, int *arr);
void output_arr(int size, int *arr);
int main()
{
    int len = 0;
    printf("输入数组长度：");
    scanf_s("%d", &len, sizeof(len));
    int *arr = (int *)malloc(len * sizeof(int));
    input_arr(len, arr);
    Selection_sort(len, arr);
    output_arr(len, arr);
    return 0;
}

void swap(int *a, int *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
void input_arr(int size, int *a)
{
    puts("请输入随机数列：");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", a + i);
    }
}
void Selection_sort(int size, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        int j = 0;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min]) // 升序
            {
                min = j;
            }
        }
        if (min != i) // 添加一个判断，如果min==i，说明最小值就是arr[i]，不需要交换
        {
            swap(arr + min, arr + i);
        }
    }
}
void output_arr(int size, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}