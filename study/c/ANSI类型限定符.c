#include <stdio.h>

int sum(const int ar[], int n); // 声明一个只读数组，这样就不会在函数中改变数组的值
const int n = 10;               // 声明一个只读变量，具有外部链接
// 使用定义在别处的外部变量，需要使用extern关键字
int main()
{
    // 对形式参数使用const,表明该函数不会使用指针改变数据,能让函数处理const和非const实参,而且能保护数据
    int marbles[10] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    printf("The total number of marbles is %d.\n", sum(marbles, 10));

    // 创建变量
    const double PI = 3.1415926;
    // PI = 3.14; // 试图修改常量的值会导致编译器报错:表达式必须是可修改的左值
    // 保护数组
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // days[0]=30; // 试图修改常量的值会导致编译器报错:表达式必须是可修改的左值

    // 保护指针,指向const的指针不能用于改变值
    double rates[5] = {8.9, 9.2, 8.7, 9.4, 9.8};
    const double *pt = rates;
    // *pt=3.3; // 试图修改常量的值会导致编译器报错:表达式必须是可修改的左值
    // pd[2]=222.2；// 不允许
    // rates[0]=99.9; // 允许,因为rates未被const限定,但是pt指向的是rates[0]，所以pt指向的值也会改变
    // pt++; //可以让pt指向别处,但不能通过pt修改值

    // 把const数据或非const数据的地址赋给指向const的指针是合法的
    double arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    const double locked[4] = {1.1, 2.2, 3.3, 4.4};
    const double *p1 = arr; // 合法
    p1 = locked;            // 合法
    p1 = &locked[1];        // 合法

    // 不能把const数据的地址赋给指向非const的指针
    //double *p2 = locked; // 不合法.这个规则非常合理,否则可以通过p2修改locked的值,这样就违背了const的初衷
    // 但是可以通过强制类型转换来实现
    double *p3 = (double *)locked; // 合法,但是不建议这么做,因为这样会使得const失去作用

    // 声明并初始化一个不能指向别处的指针
    double *const p4 = &arr[1]; // p4是一个指向double的const指针,这意味着p4的值(即存储在p4中的地址)不能改变,但是p4指向的值可以改变
    // p4=&arr[2]; // 不合法
    *p4 = 3.3; // 合法

    // 声明并初始化一个既不能指向别处,也不能改变值的指针
    const double *const p5 = &arr[2]; // p5是一个指向double的const指针,这意味着p5的值(即存储在p5中的地址)不能改变,而且p5指向的值也不能改变

    // 指针和const:把const指针赋给非const指针不安全,因为这样会使得const失去作用

    // const的位置
    float const *pfc; // const float *pfc;这二者是等价的,都是指向const float的指针。简而言之，const放在左侧任意位置，限定了指针指向的数据不能改变；const放在右侧任意位置，限定了指针本身不能改变。

    // volatile关键字
    //  volatile告诉编译器不要对这个变量进行优化,因为这个变量的值可能会被意想不到的改变,比如多线程程序中,一个线程可能会修改另一个线程的变量,这样就会导致编译器优化失效
    volatile const int loc;
    const volatile int loc1; // 这两种写法是等价的

    // restrict关键字
    //  restrict关键字只能用于指针,而且指针必须是局部变量,不能是全局变量
    int ar[10];
    int *restrict rest = ar; // rest是一个指向int的指针,这个指针是访问ar的唯一途径,这样编译器就可以进行优化,比如把数据放在寄存器中

    //_Atomic关键字
    // _Atomic关键字用于多线程编程,告诉编译器这个变量可能会被多个线程同时访问,编译器就会对这个变量进行优化,比如把变量放在寄存器中
    _Atomic int loc2;
    return 0;
}

int sum(const int ar[], int n)
{
    int total = 0;
    for (size_t i = 0; i < n; i++)
    {
        total += ar[i];
    }
    return total;
}