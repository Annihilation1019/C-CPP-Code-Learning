#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b;              // 左值必须是变量，右值可以是变量、常量、表达式、函数等，左值和右值的类型必须一致，左值和右值的类型必须是可转换的，左值是用于标识或定位储存位置的标签
    scanf("%d%d", &a, &b); // 使用空白（空格、制表符、换行符）分隔的多个输入项，每个输入项都会被依次读取并且赋值给相应的变量，如果输入的数据项个数少于变量个数，那么多余的变量会被赋值为0，如果输入的数据项个数多于变量个数，那么多余的数据项会被留在输入队列中等待下一次读取。scanf 函数的返回值为成功读取的数据项个数，如果返回值小于变量个数，说明读取失败。
    printf("y=%d     x=%d\n", a, b);
    printf("yes\n");
    // printf 函数的返回值为打印字符的个数
    system("pause");
    return 0;
}