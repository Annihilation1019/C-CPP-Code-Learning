#include <iostream>

/* 泛型编程，函数模板只是决定怎么定义函数，并没有实际生成函数，将类型作为参数传递给模板 */

template <typename T> // 模板声明，T是类型参数，可以是任意类型，包括内置类型、类、指针、引用、数组、函数等
void swapq(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

/* 显式具体化：需要为某个特殊类型提供特定实现时，意思是：不要使用swapq()模板来生成函数定义，而应使用专门为std::string类型定义的函数定义(使用特化版本之前要先定义一个模板) */
// 写法一
template <>
void swapq<std::string>(std::string &a, std::string &b)
{
    std::cout << "使用std::string的特定模板" << std::endl;
}
// 写法二
template <>
void swapq<float>(float &a, float &b)
{
    std::cout << "使用float的特定模板" << std::endl;
}

/* 非模板函数 */
void swapq(std::string &a, std::string &b)
{
    std::string temp = a;
    a = b;
    b = temp;
    std::cout << a << b << std::endl;
}

template void swapq<int>(int &a, int &b); // 显示实例化，告诉编译器生成swapq<int>的实例，即使并没有使用它，可以在编译时检查模板代码是否正确

template <typename T>
void function(T a, T b)
{
    std::cout << a << ' ' << b << std::endl;
    return;
}

/* 可以定义多个模板量 */
template <typename T1,typename T2> 
void function(T1 a, T2 b)
{
    return;
}

int main()
{
    int a = 1, b = 2;
    double c = 1.2, d = 3.4;
    long f = 4, e = 5;
    double x = 1.2, y = 3.4;
    std::string g = "hello", h = "world";

    swapq(a, b); // 隐式实例化，编译器根据传入的参数类型生成swapq<int>的实例
    swapq(c, d);
    swapq(f, e);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "f = " << f << ", e = " << e << std::endl;

    swapq(g, h); // 调用时优先级：非模板函数 > 显示具体化 > 模板函数

    function<int>(a, c); // 调用函数时的显示实例化，强制编译器生成特定类型的函数，并将c强制类型转换为int类型，这样可以匹配到模板函数
    // swapq<int>(a, c); // 错误，因为double&不能转换为int&，引用不能改变指向的对象类型

    function<>(x, y);//告诉编译器应该选择模板函数
    function<int>(x, y); //显式实例化，x和y都是double类型，但是强制编译器生成特定类型的函数
    function<int>(a, y); // 隐式实例化，编译器根据传入的参数类型生成function<int>的实例，这里仅仅指定了一个类型参数，另一个类型参数是根据传入的参数类型推导出来的
    function<int,double>(a, b); // 隐式实例化，编译器根据传入的参数类型生成function<int,double>的实例

    return 0;
}