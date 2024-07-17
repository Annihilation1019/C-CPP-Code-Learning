#include <iostream>

class Fraction
{
private:
    int num;
    int den;

public:
    Fraction(int num = 0, int den = 1)
    {
        this->num = num;
        this->den = den;
    }
    explicit operator double() const { return double(num) / den; } // C++11
    // 1. 必须是类方法，2. 没有返回类型，3. 函数名是 operator 后面接转换的类型，且不能有参数
    explicit operator int() const { return num / den; }
    // 因为转换函数没有参数因此不能对同一个运算符多次重载。
};

int main()
{
    Fraction frac(7, 3);
    double d = double(frac); // 调用operator double()，将frac转换为double，或者写成double d = frac;（没有声明为explicit）让编译器根据上下文决定
    int i = double(frac);    // 调用operator int()，将frac转换为int
    // long l = frac;//编译错误，没有定义operator long()，有二义性
    long l1 = (double)frac;   // 强制转换，调用operator double()，将frac转换为double
    double d2 = double(frac); // 调用operator double()，将frac转换为double
    std::cout << d << std::endl;
    std::cout << i << std::endl;
    std::cout << double(frac) << std::endl;
    int arr[int(frac)]; // 可能存在frac到int的转换
    return 0;
}