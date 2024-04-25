#include <iostream>

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
    Time operator+(const Time &t) const; // 定义重载运算符的函数，如此A+B就是A.sum(B)，即A.operator+(B)，A是调用方法的对象，B是传入的参数
    Time operator+(int s) const { return Time(hour + s, minute, second); }
    Time operator-(const Time &t) const; // const表明它不能修改调用对象，即不能修改*this的值
    void ShowTime() { std::cout << hour << ":" << minute << ":" << second << std::endl; }
};

int main()
{
    Time t1(10, 25, 30);
    Time t2(5, 10, 55);
    Time t3;
    t3 = t1 + t2;           // 运算符左侧是调用对象，右侧是传入参数，被解析为t1.operator+(t2)
    Time t4 = t1 - t2 + t3; // 运算符可以连续使用，被解析为(t1.operator-(t2)).operator+(t3)
    Time t5 = t1 + 4;       // 运算符可以和普通参数一起使用，被解析为t1.operator+(4)，根据声明，此处是对hour进行加法操作
    Time t7{Time(4)};
    t7.ShowTime();
    t5.ShowTime();
    t3.ShowTime();
    t4.ShowTime();
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