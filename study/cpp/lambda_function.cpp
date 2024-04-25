#include <iostream>
int main()
{
    using std::cout, std::endl;

    int a = 10;
    int b = 20;
    int c = 30;

    /* ⼤多数都是
    其所在的函数/作用域中的变量 */

    auto fun1 = [=]() -> int // -> 后面表示返回值类型，没有则不写，或者->void.
    { return a + b; };       // 捕获外部作用域所有变量，作为拷贝副本，只读
    cout << fun1() << endl;

    // auto f2 = [a]() { return b * 8; }; // 封闭函数局部变量不能在 lambda 体中引用，除非其位于捕获列表中

    auto fun2 = [&]() -> void
    { a *= 10; }; // 捕获外部作用域所有变量，作为引用使用
    fun2();
    cout << a << endl;

    []()
    { cout << "这是一个匿名lambda函数" << endl; }(); // 加上()直接调用这个函数

    [b]()
    { cout << b << endl; }(); // 按值捕获b

    [&b]()
    { b *= 10; }(); // 按引用捕获b
    cout << b << endl;

    //[&,ted]---按值访问ted,按引用访问其他动态变量

    cout << [a, &b, c]() -> int
    { return a * b * c; }();

    return 0;
}