#include <iostream>
#include <cmath>
using namespace std;
void swapr(int &a, int &b); // a,b是引用
void swapp(int *p, int *q); // p,q是指针
double cube(const double &a) { return a * a * a; };
int main()
{
    int rats = 101;
    int &rodents = rats; // rodents作为rats的引用，就像char*指的是指向char的指针，int&指的是指向int的引用
    // 上述声明允许将rats和rodents互换，它们指向同一个值和地址。

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    // 假设这样做：
    int one = 10, another = 20;
    int *p = &one;
    int &one1 = *p; // one1是p的引用，p是one的指针，所以one1是one的引用
    cout << "one = " << one << ", one1 = " << one1 << endl;
    p = &another; // 虽然改变了p的指向，但是one1仍然是one的引用
    cout << "one = " << one << ", one1 = " << one1 << endl;
    // 但是如果这样做：
    int *p1 = &one;
    int *&one2 = p1; // one2是p1的引用，p1是one的指针，所以one2是one的指针
    cout << "one = " << one << ", *one2 = " << *one2 << endl;
    p1 = &another; // 改变了p1的指向，one2也会改变
    cout << "one = " << one << ", *one2 = " << *one2 << endl;
    // 所以，引用所指向的对象类型很重要，上述例子中，一个指向int，一个指向int*，所以结果不同。

    // 引用的另一个用途是作为函数的参数，这样可以避免复制大型对象，提高效率。
    // 例如：
    int x = 5, y = 10;
    cout << "x = " << x << ", y = " << y << endl;
    swapr(x, y); // 传递引用
    cout << "x = " << x << ", y = " << y << endl;
    swapp(&x, &y); // 传递地址
    cout << "x = " << x << ", y = " << y << endl;
    // 传参时，只能将变量传递给引用，不能将表达式传递给引用，例如：
    //  swapr(x+1, y); // 错误

    // 常量引用
    //  例如：
    int r = 10;
    const int &a = r; // a是常量引用，所以不能通过a修改10的值
    // a = 20; // 错误:表达式必须是可修改的的左值

    // 临时变量、引用参数和const
    // 如果引用参数是const，编译器将在下面两种情况下生成临时匿名变量：1.实参类型正确但不是左值；2.实参类型不正确但可以转换为正确的类型。
    //（假设实参的类型与与引用参数类型不匹配，但可以被转换为引用类型，程序将创建一个正确类型的临时变量，使用转换后的实参值初始化它，然后传递一个指向该临时变量的引用）
    
    double side = 3.0;
    double *pd = &side;
    double &rd = side;
    long edge = 5L;
    double lens[4] = {2.0, 5.0, 10.0, 12.0};
    cout << "square = " << cube(side) << endl;       // 正确
    cout << "square = " << cube(lens[2]) << endl;    // 正确
    cout << "square = " << cube(rd) << endl;         // 正确
    cout << "square = " << cube(*pd) << endl;        // 正确
    cout << "square = " << cube(edge) << endl;       // 正确，edge转换为double
    cout << "square = " << cube(7) << endl;          // 正确，7转换为double
    cout << "square = " << cube(side + 1.0) << endl; // 正确，side+1.0转换为double


    // 右值引用
    // 右值引用是C++11新增的特性，它是对右值的引用，右值是指表达式结束后就不再存在的临时对象，例如：
     int &&a2 = 10; // a是右值引用
    //  int &&b = a; // 错误，a是左值
     int &&c2 = a2 + 1; // 正确，a+1是右值
    //  int &&d = a++; // 错误，a++是左值

    double &&rref = sqrt(36.00);
    double j = 15.0;
    double &&jref = 2.0 * j + 18.5;
    cout << "rref = " << rref << endl;
    cout << "jref = " << jref << endl;
}

void swapr(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swapp(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}