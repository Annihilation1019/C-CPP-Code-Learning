#include <stdio.h>
#include <stdlib.h>
void input_array(int *arr, int len);
void quick_sort(int *arr, int len);
void out_put_arr(int *arr, int len);
int main() 
{
    int len = 0;
    printf("输入数组长度：");
    scanf_s("%d", &len, sizeof(len));
    int *arr = (int *)malloc(len * sizeof(int));
    input_array(arr, len);
    quick_sort(arr, len);

}
void input_array(int *arr,int len)
{
    printf("输入乱序数列：");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", arr + i);
    }
}
void quick_sort(int *arr,int len)//升序
{
    
}
void output_arr(int *arr,int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr + i);
    }
}