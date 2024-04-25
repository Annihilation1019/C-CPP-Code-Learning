#include <iostream>
#include <string>
using std::cout, std::endl, std::cin;
namespace Std_Design
{
    class Person // 通常将类声明放在头文件中，实现放在源文件中
    {
    private: // 私有成员，只能在类内部通过成员函数访问，通常将数据成员设置为私有的
        std::string name;
        int age;
        std::string id;
        int height;
        int weight;
        bool is_overweight() // 私有成员函数（编写类的人可使用它，但使用类编写代码的人不能使用）
        {
            return weight > 200; // 如果像这样直接在类定义中提供了函数的实现，那么这个函数会自动成为内联函数
        }

    public: // 公有部分，可以通过对象访问（类的公共接口）
        void init();
        void print();
        double BMI();
    };
}

int main()
{
    Std_Design::Person p1;
    p1.init();                                       // 对象不可直接访问私有成员，只能通过公有成员函数访问，这是封装的体现（数据隐藏）
    p1.print();                                      // 不同的对象可以调用相同的方法，但数据是独立的
    Std_Design::Person p2 = p1;                      // 对象可以赋值，但是数据是独立的
    Std_Design::Person *p3 = new Std_Design::Person; // Person可以被看做像是int,char这样的数据类型，可以使用new创建动态对象
    return 0;
}

void Std_Design::Person::init()
{
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入年龄：";
    cin >> age;
    cout << "请输入身份证号：";
    cin >> id;
    cout << "请输入身高：";
    cin >> height;
    cout << "请输入体重：";
    cin >> weight;
}

void Std_Design::Person::print()
{
    cout << "姓名：" << name << endl;
    cout << "年龄：" << age << endl;
    cout << "身份证号：" << id << endl;
    cout << "身高：" << height << "cm" << endl;
    cout << "体重：" << weight << "kg" << endl;
    cout << "BMI：" << BMI() << endl;
    if (is_overweight())
        cout << "体重超标" << endl;
    else
        cout << "体重正常" << endl;
}

double Std_Design::Person::BMI()
{
    return weight * 10000.0 / height / height;
}