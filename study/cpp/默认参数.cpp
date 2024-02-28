#include <iostream>
#include <string>
using namespace std;

char left(const char *str, int n = 1);             // n的默认值为1
void test(int a, int b = 1, int c = 2, int d = 5); // 默认参数只能从右向左设置，要为某个参数设置默认值，那么它右边的所有参数都必须有默认值
int main()
{
    char str[] = "Hello, World!";
    cout << left(str, 5) << endl;
    cout << left(str) << endl; // 若省略第二个参数，则使用默认值
    test(1, 2, 3, 4);
    cout << "----------------" << endl;
    test(1, 2); // 实参从左向右赋值，若省略某个参数，则使用默认值，不能跳过中间的参数，例如test(1, ,3,4)是错误的

    return 0;
}
char left(const char *str, int n)
{
    return str[n];
}
void test(int a, int b, int c, int d)
{
    cout << a << " " << b << " " << c << " " << d << endl;
}