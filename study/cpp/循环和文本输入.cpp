#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    // 使用原始的cin进行输入
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch; // cin是行缓冲的，所以输入的时候要按回车键，这样才会把输入的字符送到缓冲区，但也因此忽略了空格符
    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin >> ch;
    }
    cout << endl
         << count << " characters read\n";
    cin.get(); // 吸收换行符

    // 使用cin.get(char)补救
    count = 0;
    cout << "Enter characters; enter # to quit:";
    cin.get(ch); // cin.get(char)是一个函数，可以读取空格符，但是不会忽略换行符
    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cout << endl
         << count << " characters read\n";

    cin.get();

    // 检测是否到达文件尾
    cout << "Enter a sentence:\n";
    count = 0;
    cin.get(ch);
    while (cin.fail() == false) // cin.fail()检测是否到达文件尾，可以替换为while(cin)
    {
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cout << endl
         << count << " characters read\n";
    //检测到EOF后，cin将两位(eofbit和failbit)都设置为1。cin.fail()和cin.eof()都返回true()，cin.get()返回EOF，EOF是一个整数，通常是-1

    cout.put('a'); // cout.put(char)是一个函数，可以输出字符
    return 0;
}