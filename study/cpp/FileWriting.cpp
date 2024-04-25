#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream outFile;
    ofstream fout; // fout和outFile是一样的，都是ofstream类型的对象，区别在于可以使用不同的对象打开和操作不同的文件，在同一时间处理多个文件。一个对象在同一时间只能维护一个文件。

    outFile.open("test.txt");
    fout.open("test1.txt"); // 接受一个C风格的字符串作为参数，打开一个文件，如果文件不存在则创建一个新文件，如果文件存在则清空文件内容。

    if (!outFile.is_open() || !fout.is_open())
    {
        cout << "open file error" << endl;
        return 0;
    }
    outFile << "hello world" << endl; // 同文件关联起来后，就可以使用流插入运算符<<向文件中写入数据，使用流提取运算符>>从文件中读取数据。
    outFile.close();
    fout << "hello world" << endl;
    outFile.open("file1.txt");
    fout.close(); // 不需要文件名参数，因为该对象已经与文件关联起来了，只需要调用close()函数就可以关闭文件。
    return 0;
}
/*步骤：
  1.包含头文件fstream
  2.创建一个ofstream对象
  3.将该ofstream对象同一个文件关联起来
  4.就像使用cout那样使用该ofstream对象*/