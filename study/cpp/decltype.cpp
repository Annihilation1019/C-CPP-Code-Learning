#include <iostream>
struct
{
    int id;
    char name;
} info;

int function(int a, int b)
{
    std::cout << a << ' ' << b << std::endl;
    return a+b;
}

template <typename T>
auto function(T a, T b) -> decltype(a + b) // auto作为一个占位符，用于推导函数的返回值类型，decltype(a + b)返回a+b的类型
{
    std::cout << "后置返回类型" << std::endl;
    return a + b;
}

template <typename T1, typename T2>
decltype(auto) function(T1 a, T2 b)
{
    std::cout << "使用decltype(auto)推导返回值类型" << std::endl;
    return a + b; // 返回值必须要有，因为decltype(auto)依据此推导类型
}
int main()
{
    /* decltype 是 C++11 引入的一个关键字，用于查询表达式的类型。decltype 关键字后面跟着一个表达式，它会返回这个表达式的类型。 */

    double *p;
    int a0;
    int &c = a0;
    decltype(1) a = 0.258; // a的类型是int
    decltype(p) b;         // b的类型是double*
    decltype(a + b) d;     // c的类型是double*

    /* 带括号的变量会被推导为引用类型 */
    decltype(a) e;       // e的类型是int
    decltype((a)) f = a; // e的类型是int&

    /* decltype(auto) 用于推导函数的返回值类型 */
    decltype(function(1, 2)) g; // g的类型是int
    decltype(auto) v = function(1.3, 2.2);

    /* 重用匿名类型 */
    decltype(info) h; // h的类型与info相同

    /* decltype用于lambda函数 */
    auto fun = [=](int a, int b) -> decltype(a + b)
    {
        std::cout << "后置返回类型" << std::endl;
        return a + b;
    };
}
