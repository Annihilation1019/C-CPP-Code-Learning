#include <stdio.h>
#define SIZE 10
int main()
{
    int arr[SIZE]; // 声明数组时最好使用符号常量来表示数组的大小
    int i;
    for (i = 0; i < SIZE; i++) // 循环给数组赋值
    {
        arr[i] = i;
    }
    // 输出数组的内容
    for (i = 0; i < SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;

    // 指定数组的大小
    int n = 5;
    int m = 8;
    float a1[5];               // 可以
    float a2[5 * 2 + 1];       // 可以，但是不推荐
    float a3[sizeof(int) + 1]; // 可以，但是不推荐
    // float a4[-4];//不可以
    // float a5[0];//不可以
    // float a6[2.0];//不可以
    float a7[(int)2.0]; // 可以
    float a8[n];        // 可以,C99之前不允许
    float a9[m + 2];    // 可以,C99之前不允许
}