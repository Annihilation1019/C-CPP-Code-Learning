#include <iostream>
int main()
{
    double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
    for (double x : prices) // x是一个新的变量（不影响原数组中的元素），用来存储prices中的每个元素的值
        std::cout << x << std::endl;
    for (double &x : prices) //&x是引用变量，可以改变原数组中的元素
    {
        x = x * 0.8;
        std::cout << x << std::endl;
    }
    for (int x : {3, 5, 2, 8, 6})
        std::cout << x << std::endl;
    return 0;
}
// 对于x和&x的理解，可以类比函数传值调用和传址调用
// 编译器会将上述形式转化为
    /* {
        auto &&__range = range;
        for (auto __begin = begin_expr, __end = end_expr; __begin != __end; ++__begin)
        {
            declaration = *__begin;
            statement
        }
    } */
    
// 所以，基于范围的 for 循环的本质是使用迭代器遍历序列，但它隐藏了迭代器的使用，让代码更简洁、更易读。