#include <iostream>
#include <string>  //本质上还是字符数组，主要区别是可以将字符串赋值给string对象，而不能直接赋值给字符数组（声明为简单变量）
#include <cstring> // 用于C-风格字符串
int main()
{
    using namespace std;
    string test1 = "hello";
    string test2 = {"world"};
    string test3{"!"};
    char c_style_string[]{"It can be used to initialize a C-style string."}; // 列表初始化用于初始化C-风格字符串
    cout << test1 << " " << test2 << test3 << endl;
    string cin_test;
    cin >> cin_test;
    cout << cin_test << endl;

    // 赋值、拼接和附加
    string test4 = "hello";
    string test_receive;
    test_receive = test4;
    cout << test_receive << endl; // 不能将数组赋给一个数组，但是可以将一个string类对象赋给另一个string类对象（更详细的说string对象可以作为被赋值者，但数组不能，数组可以给string对象赋值）
    test_receive = test2;
    cout << test_receive << endl;

    string test_append = test1 + " " + test2;
    cout << test_append << endl;
    test_append += test3;
    cout << test_append << endl; // 对变量可以做的事情，对象也可以做

    // string类的其他输入
    char c_style1[100];
    cout << "输入一个字符串：" << endl;
    strcpy(c_style1, c_style_string); // 将c_style_string复制到c_style1中
    cout << c_style1 << endl;
    strcat(c_style1, c_style_string); // 将c_style_string连接到c_style1后面
    cout << c_style1 << endl;         // 以上函数不能用于string类对象
    string test_length = "hello";
    char test_length_c[30] = "this is a test";
    cout << strlen(test_length_c) << endl; // strlen()函数用于计算C-风格字符串的长度
    cout << test_length.size() << endl;    // 注意这里的写法：test_length是一个对象，size()是一个类方法。方法是一个函数，只能通过其所属类的对象进行调用
    cout << test_length.length() << endl;  // size()和length()函数完全等效：size()的存在是为了与C++标准库的其他部分保持一致

    cin.get();
    // string类I/O
    string test_io;
    char test_io_c[100];
    cin.getline(test_io_c, 100); // getline()函数用于读取一行字符串，第一个参数是一个字符数组，第二个参数是读取的最大字符数
    cout << test_io_c << endl;
    getline(cin, test_io); // getline()函数的第一个参数是一个输入流对象，第二个参数是一个string类对象
    cout << test_io << endl;

    // 其他形式字符串字面值
    char c_style2[100] = R"(This is a "raw" string literal.)"; // 原始字符串(raw)字面值，用于避免转义字符的使用，以R"("开始，以")"结束
    cout << c_style2 << endl;
    cout << R"+*((This is 
a "raw" string literal.))+*" // 按回车不仅会移动到下一行，还会在字符串中添加换行符
         << endl;            // 原始字符串字面值的开始和结束标记可以自定义，但是必须是相同的，且不能包含括号))
    /*wchar_t wide_string[] = L"chief"; // 宽字符字面值，以L开头
    char16_t utf16_string[] = u"This is a UTF-16 string literal."; // UTF-16字符串字面值，以u开头
    char32_t utf32_string[] = U"This is a UTF-32 string literal."; // UTF-32字符串字面值，以U开头*/

    return 0;
}