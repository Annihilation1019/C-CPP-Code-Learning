#include <iostream>
#include <fstream>
class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h = 0, int m = 0, int s = 0);
    void set_time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    };
    void AddHour(int h) { hour += h; }
    void AddMinute(int m);
    void AddSecond(int s);

    Time operator+(const Time &t) const;
    Time operator-(const Time &t) const;

    /* 成员运算符重载函数有且只能有一个参数 */
    /* 类声明仍然控制了哪些函数可以访问私有数据，不违背OOP原则 */

    /* 创建友元函数：如果要为类重载运算符，并将非类的项作为第一个操作数，可以用友元函数来反转操作数的顺序 */
    friend Time operator+(int n, const Time &t); // 友元函数，加friend关键字，声明在类中但不是成员函数，但可以访问类的私有成员

    /* 友元函数重载<<和>> */
    friend std::ostream &operator<<(std::ostream &os, const Time &t)
    {
        os << t.hour << ":" << t.minute << ":" << t.second;
        return os;
    }
    
    friend std::istream &operator>>(std::istream &is, Time &t) // 主意按引用传递，否则无法修改t的值，且std::cin/std::cout对象的状态可能会被改变。例如，它的内部缓冲区可能会被填充，或者它的错误状态可能会被设置。
    {
        is >> t.hour >> t.minute >> t.second;
        return is;
    }
};

int main()
{
    Time t1(10, 25, 30);
    Time t2(5, 10, 55);
    Time t3 = t1 + t2; // 使用成员函数，t1调用+运算符重载函数，t2作为参数传递给+运算符重载函数
    Time t4 = 5 + t2;  // 使用友元函数，5作为第一个参数传递给+运算符重载函数，t2作为第二个参数传递给+运算符重载函数
    std::cout << t3 << std::endl;
    std::cout << t4 << std::endl;
    /* (std::cout << t4)相当于operator<<(std::cout,t4)它的返回值仍是一个ostream类对象，因此std::cout << t4 << t3相当于：operator<<(operator<<(std::cout,t4),t3) */
    /* 重载<<和>>运算符时，必须返回一个ostream或istream类对象的引用，这样才能实现级联操作 */

    Time t5;
    std::cin >> t5; // 使用友元函数，cin作为第一个参数传递给>>运算符重载函数，t5作为第二个参数传递给>>运算符重载函数
    std::cout << t5 << std::endl;

    /* operator<<()将输出写入到文件中：类继承属性让ostream引用可以指向ostream对象和fstream对象 */
    std::ofstream fout;
    fout.open("saving_time.txt");
    fout << t5 << std::endl;
    return 0;
}

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}
void Time::AddMinute(int m)
{
    minute += m;
    hour += minute / 60;
    minute %= 60;
}
void Time::AddSecond(int s)
{
    second += s;
    minute += second / 60;
    second %= 60;
    hour += minute / 60;
    minute %= 60;
}

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.second = second + t.second;
    sum.minute = minute + t.minute + sum.second / 60;
    sum.second %= 60;
    sum.hour = hour + t.hour + sum.minute / 60;
    sum.minute %= 60;
    return sum;
}
Time Time::operator-(const Time &t) const
{
    Time diff;
    int total_second1, total_second2;
    total_second1 = hour * 3600 + minute * 60 + second;
    total_second2 = t.hour * 3600 + t.minute * 60 + t.second;
    diff.hour = (total_second1 - total_second2) / 3600;
    diff.minute = (total_second1 - total_second2) % 3600 / 60;
    diff.second = (total_second1 - total_second2) % 60;
    return diff;
}

Time operator+(int n, const Time &t) // 定义部分不需要Time::，它不是Time类的成员函数，也不需要friend关键字（除非声明的同时定义），因为类外部说明符无效
{
    Time sum;
    sum.second = t.second + n;
    sum.minute = t.minute + sum.second / 60;
    sum.second %= 60;
    sum.hour = t.hour + sum.minute / 60;
    sum.minute %= 60;
    return sum;
}