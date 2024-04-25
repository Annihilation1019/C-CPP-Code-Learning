#include <iostream>
int main()
{
    using namespace std;
    int *pn = new int;     // 分配一个int大小的内存，返回指向该内存的地址。此时pn指向一个数据对象（为数据项分配的内存块）
    int *pn2 = new int(6); // 分配一个int大小的内存，初始化为6
    int *pn3 = new int{6}; // 分配一个int大小的内存，初始化为6(列表初始化)
    cout << sizeof(*pn) << endl;
    cout << *pn2 << endl;
    delete pn; // 后面要加上指向内存块的指针，只能用来释放new分配的内存
    delete pn2;

    // delete pn; // 不能重复释放内存，否则将导致未定义行为
    pn = nullptr;
    pn2 = nullptr; // 因此释放内存后，要把指针变成空悬指针，不再指向有效的内存块，此时不能再使用该指针，delete NULL是安全的

    // 使用new创建动态数组
    // 静态联编：编译时分配内存，数组大小必须是常量表达式
    // 动态联编：运行时分配内存，数组大小可以是变量。运行阶段需要数组则创建它；不需要则不创建。
    int *array = new int[10]; // 分配10个int大小的内存，new运算符返回数组的首地址
    delete[] array;           // 释放数组内存，delete后面要加上[]，否则只会释放第一个元素的内存，其他元素的内存泄漏

    /*注意：
    -不要使用delete来释放不是new分配的内存；
    -不要使用delete释放同一个内存两次，结果是未定义的；
    -如果使用new[]为数组分配内存，则应使用delete[]来释放；
    -如果使用new[]为一个实体分配内存，则应使用delete(没有方括号)来释放
    -对空指针应用delete是安全的*/
    // 实际上程序确实跟踪了分配的内存量，以便delete[]能够释放内存。但这种信息不是公用的，例如不能用sizeof来获取动态数组的大小。

    // 使用动态数组
    int *parr = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // C++11标准允许使用列表初始化，但并不支持C语言中的指定初始化器
    int *parr_origin = parr;                               // 保存数组首地址，以便释放内存
    for (int i = 0; i < 10; i++)
    {
        parr[i] = i; // 等效于*(parr+i)=i
    }
    cout << parr[0] << endl;
    parr += 2;
    cout << parr[0] << endl; // parr指向第三个元素
    delete[] parr_origin;    // 如果是delete[] parr，实际上是在删除一个不由new分配的内存的指针，将导致未定义行为

    // 其他数组（静态联编与其对应的动态联编）
    int arr2[10][10];                  // 10*10的二维数组
    int(*parr2)[10] = new int[10][10]; // 分配10*10个int大小的内存，返回指向该内存的地址

    int *arr3[10];
    int **parr3 = new int *[10]; // 分配10个指针的内存，返回指向该内存的地址

    int(*arr4[5])[10];
    int **parr4 = new int *[5]; // 分配5个指针的内存，返回指向该内存的地址
    for (int i = 0; i < 5; i++)
    {
        parr4[i] = new int[10]; // 分配10个int大小的内存，返回指向该内存的地址
    }
    for (int i = 0; i < 5; i++)
    {
        delete[] parr4[i];
    }
    delete[] parr4;
    // 先给这些指针数组分配内存，然后再给数组里面每个指针分配内存，释放时同理，一共两次new，两次delete
    return 0;
}