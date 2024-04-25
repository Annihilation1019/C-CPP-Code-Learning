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
int find_min(int begin, int end, int arr[])
{
    int min = begin;
    for (int i = begin + 1; i <= end; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    return min;
}
void Selection_sort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        swap(&arr[i], &arr[find_min(i, len, arr)]);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
    }
    Selection_sort(arr, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}