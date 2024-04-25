#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ifstream fin;

    inFile.open("test.txt");
    fin.open("test1.txt");

    if (!inFile.is_open() || !fin.is_open()) // 如果文件被成功打开，方法is_open()返回true，否则返回false。
    {
        cout << "open file error" << endl;
        return 0;
    }
    char str[50], str1[50];
    inFile >> str;
    cout << str << endl;
    fin.getline(str1, 100);
    cout << str1 << endl;
    inFile.close();

    return 0;
}