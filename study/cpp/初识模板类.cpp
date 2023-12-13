#include <iostream>
#include <vector>
#include <array>
int main()
{
    using namespace std;

    // 模板类vector，用于存放任意类型的动态数组，内置new和delete，可以自动扩容等（存放在堆中）
    vector<int> v_int={1,2,3,4,5,6,7,8,9};        // 定义一个存放int类型的vector
    vector<double> v_double;  // 定义一个存放double类型的vector
    vector<string> v_string;  // 定义一个存放string类型的vector
    vector<float> v_float(5); // 定义一个存放float类型的vector，初始化为5个元素

    // 模板类array，用于存放任意类型的静态数组（存放在栈中）
    array<int, 5> a_int{1, 2, 3, 4, 5};          // 定义一个存放int类型的array，初始化为5个元素（与vector不同的是，e_num不能为变量）
    cout << a_int[0] << " " << a_int[4] << endl; // 无论是数组、vector还是array都支持标准数组表示法访问
    cout << a_int.size() << endl;                // 5
    cout << v_int[2] << endl;
    return 0;
}