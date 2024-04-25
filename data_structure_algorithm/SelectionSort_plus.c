// 时间复杂度：O(n^2) 空间复杂度：O(1)
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
    int begin = 0;
    int end = size - 1;
    while (begin <= end)
    {
        int max = begin;
        int min = begin;
        for (int i = begin + 1; i <= end; i++)
        {
            if (arr[i] > arr[max])
            {
                max = i;
            }
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        swap(arr + begin, arr + min);
        if (begin == max) // 如果最大值在begin位置，经过上一步交换，最大值已经在min位置，所以要更新max
        {
            max = min;
        }
        swap(arr + end, arr + max);
        begin++;
        end--;
    }
}
void output_arr(int size, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}