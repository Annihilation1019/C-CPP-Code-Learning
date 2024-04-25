#include <stdio.h>
#include <string.h>
#include <math.h>
#include <tgmath.h> /*泛型数学库,可以使用泛型宏*/
#include <stdlib.h>
#define NDEBUG        /*取消assert()函数*/
#include <assert.h>   /*断言库*/
#include <stdarg.h>   /*可变参数库*/
#pragma               // 预处理器指令，用于指示编译器如何处理源代码，#pragma once表示只编译一次，#pragma pack(n)表示按照n字节对齐，#pragma pack()表示取消对齐，#pragma warning(disable:4996)表示取消4996号警告
#define XNAME(n) x##n /*##运算符用于连接两个参数*/

#define PRINT_XN(n) printf("x" #n "=%d\n", x##n)
/*#运算符用于将参数换为字符串*/
#define PR(format, ...) printf(format, ##__VA_ARGS__) // __VA_ARGS__用于表示可变参数,##用于表示可变参数为空时不输出逗号

#define ISSPACE(ch) (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v') // 判断是否为空白字符，用圆括号把宏参数和整个替换体括起来，防止替换体中的运算符优先级出错
#define MAX 200
#define SYS 1
#undef ISSPACE                                                        // 取消宏定义，即使没有定义过MAX也不会报错，如想使用一个名称但不想使用宏定义，可以使用#undef取消宏定义
#define abs(x) _Generic((x), int: 1, float: 2, double: 3, default: 4) // 泛型选择，根据参数类型选择对应的宏，1234都可以替换成其他宏
// 条件编译
#ifndef MIN // 如果MIN没有定义过，就定义MIN
#define MIN 0
#endif
#if MAX > MIN // 如果MAX大于MIN，就定义MAXMIN
#define MAXMIN 1
#elif MAX < MIN // 如果MAX小于MIN，就定义MAXMIN
#define MAXMIN 0
#endif
#if SYS == 1
#define SYS1 2
#elif SYS == 2
#define SYS2 3
#else
#define SYS3 4
#endif

// 定义泛型宏
#define RAD_TO_DEG (180 / (4 * atanl(1))) // 4 * atanl(1)表示π

#define SIN(X) _Generic((X), long double: sinl((X) / RAD_TO_DEG), default: sin((X) / RAD_TO_DEG), float: sinf((X) / RAD_TO_DEG)) // 泛型选择，根据参数类型选择对应的宏

inline static int max(int a, int b) // inline只是一个建议(类似register)，编译器可以选择忽略(比如函数体太大，或者递归调用等)
{
    return a > b ? a : b;
}
char *x10 = NULL;
void clear(void);
int cmp(const void *p1, const void *p2);
void f1(int n, ...);
int main()
{
    int XNAME(1) = 14; // 预处理器会将XNAME(1)替换为x1
    int XNAME(2) = 20;
    PRINT_XN(1); // 预处理器会将PRINT_XN(1)替换为printf("x1=%d\n",x1)
    PRINT_XN(2);
    PR("hello world\n"); // 预处理器会将PR("hello world\n")替换为printf("hello world\n")
    PR("x1=%d,x2=%d\n", x1, x2);

    // 预定义宏
    printf("File:%s\n", __FILE__);             // __FILE__表示当前文件名
    printf("Date:%s\n", __DATE__);             // __DATE__表示当前日期
    printf("Time:%s\n", __TIME__);             // __TIME__表示当前时间
    printf("Line:%d\n", __LINE__);             // __LINE__表示当前行号
    printf("ANSI:%d\n", __STDC__);             // __STDC__表示ANSI标准的C程序
    printf("Function:%s\n", __func__);         // __func__表示当前函数名
    printf("Function:%s\n", __FUNCTION__);     // __FUNCTION__表示当前函数名
    printf("Version:%ld\n", __STDC_VERSION__); //__STDC_VERSION__表示C语言标准的版本号

    // 泛型选择
    float x;
    int y;
    printf("%d\n", abs(x));
    printf("%d\n", abs(y));

    // 内联函数(C99)(本质上是宏，但是比宏多了类型检查，运行效率高，但是会增加代码量)
    printf("%d\n", max(1, 2));
    // 由于并未给内联函数预留单独的代码块，所以无法获得内联函数的地址(实际上也可以，不过这样做会让编译器生成一个非内联函数，这样就失去了内联函数的意义)
    // 内联函数定义与函数调用必须在同一个文件中，否则编译器会将内联函数当作普通函数处理

    //_Noreturn关键字(C11)表示函数不会返回，可以用于告诉编译器某个函数不会返回，这样编译器就可以优化代码
    //_Noreturn void exit(int status) ; // exit函数不会返回，所以可以这样

    // 定义泛型宏
    printf("%lf\n", SIN(30.0));
    printf("%lf\n", SIN(30.0F));
    // 引入tgmath.h后可以不用SIN宏，直接使用sin函数

    // 通用工具库
    // exit()和atexit()函数
    // exit()函数用于正常退出程序，atexit()函数用于在程序退出时执行某个函数，可以注册多个函数，按照注册的相反顺序执行
    int x10 = 0;
    atexit(clear); // 注册clear函数，传递函数地址即可
    if (scanf("%d", &x10) == 1)
    {
        puts("ok");
    }
    else
    {
        puts("error");
        exit(1); // 即使没有显式调用exit()函数，程序也会在main函数结束时隐式调用exit()函数
    }
    // exit()函数会执行清理程序，关闭文件，释放内存等，但是abort()函数不会执行清理程序，直接退出程序

    // qsort()快速排序
    int arr[] = {1, 3, 2, 5, 4};
    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp); // qsort()函数的第一个参数是待排序数组的首地址，第二个参数是数组元素个数，第三个参数是每个元素的大小，第四个参数是比较函数，比较函数的参数是两个待比较的元素的地址。qsort()函数会根据比较函数的返回值来判断两个元素的大小关系，如果返回值小于0，表示第一个元素小于第二个元素，如果返回值等于0，表示两个元素相等，如果返回值大于0，表示第一个元素大于第二个元素
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }

    // assert()断言
    // assert()函数用于在程序中检查某个条件是否满足，如果满足就继续执行，如果不满足就终止程序
    // assert()函数的参数是一个表达式，如果表达式的值为真，就什么都不做，如果表达式的值为假，就终止程序，并打印出错信息
    // assert()函数只在调试模式下有效，如果在发布模式下，assert()函数会被忽略
    int z = 4;      // z可能是一段复杂程序的产物，调试时对其进行检测
    assert(z == 5); // 如果z不等于5，就终止程序，调用abort()；如果认为已经排除了bug，可以把#define NDEBUG放在#include <assert.h>之前，这样assert()函数就会被忽略

    //_Static_assert(C11)
    //_Static_assert()用于在编译时检查某个条件是否满足，如果满足就继续编译，如果不满足就终止编译;第一个参数是整型常量表达式，第二个参数是字符串常量，用于在编译时打印出错信息
    _Static_assert(sizeof(int) == 4, "int must be 4 bytes"); // 如果int不是4字节，就终止编译，打印出错信息

    // string.h库中的memcpy()函数和memmove()函数(参数都一样，但是memmove()函数可以处理内存重叠的情况，memcpy()更快)
    char str[] = "Hello, World!";
    // Move "World!" to the beginning of the string
    memmove(str, str + 7, 6); // 源内存区域（str + 7）和目标内存区域（str）重叠。
    // memmove()函数会先把源内存区域的数据拷贝到临时内存区域，然后再把临时内存区域的数据拷贝到目标内存区域，这样就不会出现数据覆盖的问题，而memcpy()是两个指针同时移动，所以会出现数据覆盖的问题。
    printf("%s\n", str); // Outputs "World!"
    int arr1[] = {1, 2, 3, 4, 5};
    memmove(arr1 + 2, arr1, 3 * sizeof(int)); // 把arr1的前3个元素拷贝到arr1的后3个元素，这样就不会出现数据覆盖的问题
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        printf("%d ", arr1[i]);
    }

    // stdarg.h库中的可变参数
    // 1.提供一个使用省略号的函数原型；
    // 2.在函数定义中创建一个va_list类型变量；
    // 3.使用宏把该变量初始化为一个参数列表；
    // 4.用宏访问参数列表；
    // 5.用宏完成清理工作；
    printf("\n");
    f1(3, 11, 22, 30);
    return 0;
}

void clear(void) // atexit()函数注册的函数必须是无参无返回值的函数
{
    puts("all clear!");
}

int cmp(const void *p1, const void *p2) // 比较函数，按照大小等三种情况返回负数，0，正数或正数，0，负数
{
    return *(int *)p1 - *(int *)p2; // 强转为int指针，再解引用取值
    // return *(int *)p2 - *(int *)p1; // 降序
}

void f1(int n, ...) // 至少有一个形参和一个省略号且省略号必须放在最后，标准中用parmN描述这个形参，传递给该形参的实际上是省略号部分代表的参数数量
{
    va_list ap;      // 声明一个存储参数(省略号部分)的对象
    va_start(ap, n); // 把参数列表拷贝到ap中，第二个参数是parmN，表示省略的参数个数
    for (int i = 0; i < n; i++)
    {
        int x = va_arg(ap, int); // 从ap中取出一个参数，第二个参数是参数的类型，每调用一次va_arg()函数，ap就会指向下一个参数
        printf("%d ", x);
    }
    va_end(ap); // 清理工作
}