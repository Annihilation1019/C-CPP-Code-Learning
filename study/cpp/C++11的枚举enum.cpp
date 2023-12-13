#include <iostream>
enum Color
{
    red,
    yellow,
    blue,
    green,
    white,
    black,
    brown,
};
int main()
{
    Color cpp_test;
    cpp_test = red; // valid
    // cpp_test = 1;   // invalid,不能将"int"类型的值赋给"Color"类型的实体

    // cpp_test++; // invalid
    // cpp_test = red + blue;//invalid，对于枚举只定义了赋值运算符，没有为枚举类型定义算术运算符

    int i = red + 3;       // valid，枚举类型可以隐式转换为整型(但整型类型不能自动转换为枚举类型)
    Color test = Color(3); // valid，枚举类型可以强制转换为整型（前提是int值是有效的）
    std::cout << i << std::endl;
    test = Color(100); // 未定义行为
    std::cout << test << std::endl;

    // 枚举的取值范围：上限：大于枚举最大值且最小的2的幂；下限：最小值如果大于等于0，则下限为0，否则为小于枚举最小值且最大的2的幂减1的相反数
    enum Food
    {
        bread,
        cheese,
        apple = 10,
    } food;
    food = Food(15);                // 2^4-1=15是上限，0是下限
    std::cout << food << std::endl; 
    return 0;
}