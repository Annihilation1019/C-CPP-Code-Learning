#include <iostream>
int main()
{
    using namespace std;
    const int LEN = 10;

    // cin存在的问题：使用空白来确定字符串的结束位置（空格、制表符、换行符）
    char str[LEN];
    char str1[LEN];
    cout << "输入一个字符串：" << endl; // 如果输入的是两个单词，则不会等待下一次输入了，因为cin会把空格当作字符串的结束，而且会把空格从输入流中删除，所以第二次输入时不会等待，而是直接读取输入流中的内容
    cin >> str;
    cout << "输入的字符串是：" << str << endl;
    cout << "再输入一个字符串：" << endl;
    cin >> str1;
    cout << "输入的字符串是：" << str1 << endl;

    // 面向行的输入getline() 第一个参数是存储的数组，第二个参数是数组的长度，至多读取LEN-1个字符，余下空间存储'\0'
    cout << "输入一个字符串：" << endl;
    cin.getline(str, LEN);                     // 注意：此时缓冲区剩下一个换行符，cin.getline()读取到换行符停止，并用空字符替换换行符
    cout << "输入的字符串是：" << str << endl; // 所以打印出来的字符串是空的
    cout << "再输入一个字符串：" << endl;
    cin.getline(str1, LEN);
    cout << "输入的字符串是：" << str1 << endl;

    // 面向行的输入get() 其中一种变体与getline()相同但不再读取并丢弃换行符而是将其留在缓冲区，另一种变体（不带参数）读取单个字符
    char name[LEN], name1[LEN];
    cout << "输入姓名：" << endl;
    cin.get(name, LEN).get(); // 读取姓名，然后读取并丢弃换行符
    cin.get(name1, LEN);      // cin.get(name, LEN);cin.get();cin.get(name1, LEN);等效于cin.getline(name, LEN).getline(name1, LEN);

    cout << "姓名是：" << name << endl;
    cout << "姓名是：" << name1 << endl;

    return 0;
}