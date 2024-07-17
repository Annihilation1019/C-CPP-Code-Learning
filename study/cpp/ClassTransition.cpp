#include <iostream>
using std::cout, std::endl;

class Lenth
{
private:
    int Centi;
    int Met;
    int Kilo;

public:
    Lenth() = default;
    Lenth(int Centi, int Met = 0, int Kilo = 0); // 转换构造函数指定了从 int 类型到 Lenth 类型的转换
    ~Lenth() = default;
    void show() const { cout << Centi << ' ' << Met << ' ' << Kilo << endl; }
};

Lenth::Lenth(int Centi, int Met, int Kilo)
{
    this->Centi = Centi;
    this->Met = Met;
    this->Kilo = Kilo;
}

class Weight
{
private:
    int Gram;
    int Kilo;
    int Ton;

public:
    explicit Weight(int Gram, int Kilo = 0, int Ton = 0); // explicit 关键字防止隐式转换
    ~Weight() = default;
};

Weight::Weight(int Gram, int Kilo, int Ton)
{
    this->Gram = Gram;
    this->Kilo = Kilo;
    this->Ton = Ton;
}

void test(Lenth obj)
{
    obj.show();
}

int main()
{
    Lenth obj;
    obj = 100; // 只有接受一个参数的构造函数（或只有一个参数没有默认值）才能这样赋值，这是隐式转换
    Weight obj2(100, 0, 0);
    // obj2 = 100; // 这样赋值是隐式转换，如果构造函数前加上 explicit 关键字，就不能这样赋值
    obj = Lenth(100);   // 这样赋值是显示转换
    test(100);          // 这样传参是隐式转换
    Lenth obj3 = 100.2; // 允许构造函数转换其他参数类型（当且仅当不存在二义性）
    // Lenth obj4{100.2};//{}禁止窄化转换
    return 0;
}