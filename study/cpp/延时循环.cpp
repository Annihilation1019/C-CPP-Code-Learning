#include <iostream>
#include <ctime>
int main()
{
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC; // 该常量表示每秒钟的处理器时钟数
    cout << "starting\a\n";
    clock_t start = clock(); // clock()函数返回程序执行起（一般为程序的开头），处理器时钟所使用的时间
    while (clock() - start < delay)
        ; // 最开始时clock()=start，随着循环进行，clock()的值会越来越大，直到clock() - start < delay不成立，循环结束
    cout << "done \a\n";
    return 0;
}