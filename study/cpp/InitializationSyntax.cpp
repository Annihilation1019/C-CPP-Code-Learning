#include <iostream>
int main()
{
    int a = 1; // 拷贝初始化
    int b(2);  // 直接初始化，两种基本上等效

    int c1 = {3};
    int c2{3}; // C++11标准允许这种方式，可以省略等号，C语言不允许省略等号

    int d = {}; // 不允许窄化转化，即不允许将浮点数转换为整数，但是允许将整数转换为浮点数
    int e{};    // 大括号内可以不包含任何值，这样变量会被初始化为0

    double earnings[4]{1.2e4, 1.6e4, 1.1e4, 1.7e4}; // C++11标准允许这种方式，可以省略等号，C语言不允许省略等号
    float balances[10]{};                           // 大括号内可以不包含任何值，这样数组中的所有元素都会被初始化为0

    // 带有{}的列表初始化在C++11中不允许窄化转化，但C语言允许
    std::cout << a << b << c1 << c2 << d << e << std::endl;
    return 0;
}