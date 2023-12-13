//时间复杂度：最好O(nlogn) 最坏O(n^2)，空间复杂度：O(log n)
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
// Partition by pivot
int partition(int *array, int start, int end)
{
    int pivot = array[end];
    int i = start - 1;
    for (int j = start; j < end; j++) // j从头开始遍历，i紧随其后，只要遇到比基准值小的，就把i后面一个和j交换(也就是说，j逐个遍历，把比基准值小的依次放到最前面去，这样大的全部集中到后面)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array + i, array + j);
        }
    }
    swap(array + i + 1, array + end); // i的后面一个一定是比基准值大的，直接交换二者即可

    return i + 1;
}
// Quick Sort
void quick_sort(int *array, int start, int end)
{
    if (start < end)
    {
        int q = partition(array, start, end);
        quick_sort(array, start, q - 1);
        quick_sort(array, q + 1, end);
    }
}
int main(void)
{
    int n;
    printf("输入数组大小：");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    quick_sort(arr, 0, n - 1);
    // Print result
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}