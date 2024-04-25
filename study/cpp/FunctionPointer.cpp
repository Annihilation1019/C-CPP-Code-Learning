#include <iostream>
using namespace std;
const double *f1(const double ar[], int n);
const double *f2(const double[], int);
const double *f3(const double *, int); // 特征标和返回类型都相同

const double av[3] = {1112.3, 1542.6, 2227.9};
int main()
{
    const double *(*p1)(const double *, int) = f1;
    auto p2 = f2; // 使用c++11自动推断类型

    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl; // 返回值是指针，所以要解引用

    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
    auto pb = pa; // 使用c++11自动推断类型
    double px = *pa[0](av, 3);
    double py = *(*pa[1])(av, 3); // 两种调用方式等效
    auto pc = &pa;                // pc是指向数组的指针，指向的数组是指针数组，每个指针指向一个函数，函数的返回值是指针，指向double，所以pc的类型是const double *(*(*pc)[3])(const double *, int)
}

const double *f1(const double *ar, int n)
{
    return ar;
}
const double *f2(const double ar[], int n)
{
    return ar + 1;
}
const double *f3(const double ar[], int n)
{
    return ar + 2;
}