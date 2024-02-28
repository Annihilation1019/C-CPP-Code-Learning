#include <iostream>

// 函数重载：根据参数类型（函数特征标）

void print(int i)
{
    std::cout << "Here is int: " << i << std::endl;
}
void print(long l)
{
    std::cout << "Here is long: " << l << std::endl;
}
void print(double f)
{
    std::cout << "Here is float: " << f << std::endl;
}

void print(char const *c)
{
    std::cout << "Here is char*: " << c << std::endl;
}
void print(double &f) // 类型引用和类型本身是一样的，所以不能重载
{
    std::cout << "Here is double &x: " << f << std::endl;
}

// 匹配函数时，并不区分const和非const，所以不能通过const来重载函数
void af(int i) {}
void af(const int i) {}
// 但是const可以用于区分指针参数的重载函数
void dribble(char *bits);
void dribble(const char *bits);
void dabble(char *bits);
void drivel(const char *bits);

// 重载引用参数
void fun(double &r1) {}       // 匹配左值
void fun(const double &r2) {} // 匹配左值和右值
void fun(double &&r3) {}      // 匹配右值

int main()
{
    unsigned int i = 10;
    double d = 10.10;
    double &f = d;
    const char *c1 = "ten";
    char *c2 = "ten";
    print(10);
    print(10.10);
    print("ten");
    // print(i);// 没有匹配的原型并不会自动停止使用其中的某个函数，因为C++将尝试使用标准类型转换强制进行匹配。以上代码存在多种转换方式，所以编译器会报错。

    // 通过强制类型转换来解决
    print((int)i);

    // print(f);//参数f与double f和double &f都匹配，所以编译器报错

    dribble(c1); // dribble(const char *bits)
    dribble(c2); // dribble(char *bits)
    // dabble(c1); // 无法匹配
    dabble(c2); // dabble(char *bits)
    drivel(c1); // drivel(const char *bits)
    drivel(c2); // drivel(const char *bits) 非const赋给const是合法的，反之非法


    // 重载引用参数
    // 遇到参数可以被多个重载函数匹配时，编译器会选择最佳匹配
    double x = 10.10;
    const double y = 10.10;
    fun(x);     // 匹配fun(double &)
    fun(y);     // 匹配fun(const double &)
    fun(10.10); // 匹配fun(double &&)
    fun(x + y); // 匹配fun(double &&)
    return 0;
}

void dribble(char *bits)
{
    std::cout << "char *bits" << std::endl;
}
void dribble(const char *bits)
{
    std::cout << "const char *bits" << std::endl;
}
void dabble(char *bits)
{
    std::cout << "char *bits" << std::endl;
}
void drivel(const char *bits)
{
    std::cout << "const char *bits" << std::endl;
}