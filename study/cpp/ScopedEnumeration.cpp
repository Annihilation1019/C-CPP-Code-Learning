#include <iostream>
enum class Egg
{
    small,
    medium,
    large
}; // class<=>struct
enum class T_shirt
{
    small,
    medium,
    large,
    xlarge
}; // C++11 引入的枚举类，使其具有类作用域
class Goods
{
private:
    int price;
    Egg egg;
    T_shirt shirt;

public:
    Goods(Egg egg = Egg::small, T_shirt shirt = T_shirt::medium) // 使用枚举名限定枚举量，就像使用类名限定类成员一样
    {
        this->egg = egg;
        this->shirt = shirt;
    };
    ~Goods() = default;
    void setPrice(int price) { this->price = price; };
    Egg user_gets(Egg egg)
    {
        std::cout << "User gets an egg." << std::endl;
        return egg;
    };
};

int main()
{
    Goods goods;
    goods.setPrice(100);
    goods.user_gets(Egg::large);

    // int a=Egg::large; // error: cannot convert 'Egg' to 'int' in initialization
    int b = int(Egg::medium); // 显式转换是被允许的
    std::cout << b << std::endl;

    /* C++11的作用域内枚举底层类型为int，也可以自主选择 */
    enum class Color : char
    {
        red,
        green,
        blue
    };
    std::cout << sizeof(Color) << std::endl; // 1
    std::cout << sizeof(Egg) << std::endl;   // 4
    return 0;
}