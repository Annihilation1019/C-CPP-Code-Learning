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
void Bubble_sort(int arr[], int len)
{
    char flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] < arr[i + 1]) // 降序
            {
                swap(&arr[i], &arr[i + 1]);
                flag++;
            }
        }
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
    Bubble_sort(arr, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}