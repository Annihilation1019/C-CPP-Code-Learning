#include <stdio.h>
union hold
{
    int digit;
    double bigfl;
    char letter;
}; // 共用一个存储空间，共用体的大小等于最大成员的大小

// 匿名联合
union u_tag
{
    int ival;
    union
    {
        char str;
        int len;
    };
};

// 枚举类型(提高可读性和可维护性)
enum spectrum
{           // 枚举符，配合switch语句使用可作为标签
    red,    // 0
    orange, // 1
    yellow, // 2
    green = 10,
    blue,  // 11
    violet // 12
};         // 枚举量的值默认从0开始，依次递增
int main()
{
    // 三个与hold类型相关的变量
    union hold fit; // 分配足够的空间来存储最大的成员
    union hold save[10];
    union hold *pu = &fit; // 指向共用体的指针
    // 使用成员运算符
    fit.letter = 'A';
    fit.digit = 15;
    fit.bigfl = 2.71828;
    printf("fit.letter = %lf\n", fit.bigfl);

    // 联合的初始化
    union hold valA = {.letter = 'A'};
    union hold valB = {15.2};
    printf("valA.letter = %d\n", valA.digit);

    //使用枚举常量
    enum spectrum color;
    color = blue;
    printf("color = %d\n", color);
    return 0;
}
