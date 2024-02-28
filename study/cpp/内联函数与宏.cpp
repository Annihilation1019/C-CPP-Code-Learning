#include <iostream>
using namespace std;

#define SQUARE(X) (X * X) // 宏不能按值传递参数

inline int max(int a, int b) // inline被视为一种请求，编译器可以忽略这个请求（函数过大或函数调用了自己）
{
    return a > b ? a : b; // 使用内联函数的好处是，可以减少函数调用的开销，提高程序的运行效率
}

int main()
{
    int a = 1, b = 2;
    cout << max(a, b) << endl;
    cout << SQUARE(5.0) << endl;
    cout << SQUARE(4.5 + 7.5) << endl; // 4.5 + 7.5 * 4.5 + 7.5
    cout << SQUARE(b++) << endl;       // b++ * b++
    cout << SQUARE(++a) << endl;       // ++a * ++a

    // 上述的SQUARE宏定义中，如果传入的参数是表达式，那么会出现错误，因为宏定义只是简单的文本替换，不会进行类型检查，不会进行作用域检查

#undef SQUARE                 // 取消宏定义
#define SQUARE(X) ((X) * (X)) // 使用括号可以避免上述的错误，(4.5+7.5)*(4.5+7.5)，但是(b++) * (b++)还是不会达到预期的效果
    // 为了避免这种情况，可以使用内联函数

    cout << SQUARE(4.5 + 7.5) << endl;
    return 0;
}