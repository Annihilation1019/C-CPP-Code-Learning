#include <stdio.h>
#include <stdlib.h>
int sum(int a[], int n);
void show(int (*p)(int a[], int n), int *a); // 声明一个函数，函数的返回值是void类型的，函数的参数是一个指针，指向一个函数，函数的返回值是int类型的，函数的参数是int a[], int n。
void show_return(int n);
int (*sump)(int a[], int n); // 声明一个指针，指向一个函数，函数的返回值是int类型的，函数的参数是int a[], int n。
// 要声明一个指向特定类型函数的指针，可以先声明一个该类型的函数，然后把函数名替换成(*指针变量名)形式的表达式。然后，pf就成为指向该类型函数的指针。
int main()
{
    printf("函数sum()的地址是%p\n", sum); // 函数名可以用作表示函数的地址(函数代码起始处的地址)，也就是说，函数名是一个指针常量
    int arr[5] = {1, 2, 3, 4, 5};
    sump = sum;                              // 把函数sum()的地址赋给指针变量sump
    printf("求和为：%d\n", (*sump)(arr, 5)); // 由于历史原因，(*sump)(arr, 5)和sump(arr, 5)是等价的
    show(sum, arr);                          // 把函数sum()的地址作为参数传递给函数show();
    show_return(sum(arr, 5));                // 把函数sum()的返回值作为参数传递给函数show_return();
    return 0;
}

int sum(int a[], int n)
{
    int i, s = 0;
    for (i = 0; i < n; i++)
        s += a[i];
    return s;
}
void show(int (*p)(int a[], int n), int *a) // 以函数指针作为其中一个参数
{
    printf("通过函数调用函数：%d\n", (p)(a, 5));//在函数中使用作为参数被传入的函数时，直接p()或(*p)()都可以
}
void show_return(int n)
{
    if (n == 15)
    {
        printf("可以传递函数返回值作为参数");
    }
}