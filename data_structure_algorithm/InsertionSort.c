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
void insertion_sort(int arr[], int len)
{
    int j;
    for (int i = 1; i < len - 1; i++)
    {
        j = i + 1;
        /* 连续冒泡，直到有比它小/大的 */
        while (j - 1 >= 0 && arr[j] < arr[j - 1])
        {
            swap(&arr[j], &arr[j - 1]);
            j--;
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
    insertion_sort(arr, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}