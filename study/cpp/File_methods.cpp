#include <iostream>
#include <fstream>
int main()
{
    using namespace std;

    ifstream inFile;
    inFile.open("test2.txt"); // 打开文件
    if (!inFile.good())       // 没有任何错误时返回true
                              // 可以精简为if(!inFile)
    {
        cout << "open file error" << endl;
        if (inFile.eof()) // 判断是否到达文件末尾
        {
            cout << "end of file" << endl;
        }
        else if (inFile.fail()) // 判断是否读取失败（类型不匹配，不检查底层硬件错误）
        {
            cout << "read file error" << endl;
        }
        else if (inFile.bad()) // 判断是否读取失败（文件受损和硬件故障、磁盘空间不足等系统级别错误）
        {
            cout << "read file error" << endl;
        }
        else
        {
            cout << "unknow error" << endl;
        }
        return 0;
    }
}