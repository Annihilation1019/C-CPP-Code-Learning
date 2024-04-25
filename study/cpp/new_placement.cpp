#include <iostream>
int main()
{
    char buffer1[100];
    char buffer2[100];
    int *p1 = new (buffer1) int[5]{1, 2, 3, 4, 5}; // 不分配内存，，不跟踪哪些内存单元已经被使用，直接在buffer1上创建int对象
    int *p2 = new (buffer2 + 1) int(5);            // 不分配内存，直接在buffer2上创建int对象
    double *p3 = new (buffer1) double(3.1415926);
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "&buffer1: " << (void *)buffer1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "&(buffer2+1): " << (void *)(buffer2 + 1) << std::endl;
    std::cout << "&buffer2: " << (void *)buffer2 << std::endl;
    std::cout << "p3: " << *p3 << std::endl;
    // delete[] p1; // 不能delete，因为不在管辖范围内，buffer是栈上的内存
    return 0;
}