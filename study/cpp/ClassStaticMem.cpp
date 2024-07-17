
/* 这是一个不完整的程序，仅展示静态成员变量的特性 */

#include <iostream>
#include <string.h>
class Date
{
private:
    static const int century = 21; // const和enum可以在类声明中初始化
    enum Week
    {
        Mon = 1,
        Tue,
        Wed,
        Thu,
        Fri,
        Sat,
        Sun
    }; // 静态枚举成员变量，所有对象共享
    static int year; // 程序只创建一个静态成员变量，所有对象共享。但不能在对象中初始化，只能在类外初始化
    int month;
    int day;
    int week;
    static int obj_num;
    char *weather;

    char buffer[100];

public:
    Date(int month = 1, int day = 1, int week = 1, const char *wea = "sunny");
    ~Date();
    int *getAdd()
    {
        return &year;
    }
    int getObjNum()
    {
        return obj_num;
    }
    void print()
    {
        std::cout << "Year: " << year << std::endl;
        std::cout << "Month: " << month << std::endl;
        std::cout << "Day: " << day << std::endl;
        std::cout << "Week: " << week << std::endl;
        std::cout << "Weather: " << weather << std::endl;
    }
};

Date::Date(int month, int day, int week, const char *wea)
{
    this->month = month;
    this->day = day;
    this->week = week;
    this->weather = new char[strlen(wea) + 1];
    strcpy(this->weather, wea);
    obj_num++;
}
Date::~Date()
{
    delete[] weather;
    obj_num--;
    std::cout << "OK" << std::endl;
}

int Date::year = 2024; // 静态成员变量初始化，初始化应在方法文件中，声明应在头文件中
int Date::obj_num = 0;
int main()
{
    {
        Date d1, d2(5, 4), d3(12, 25, 50, "rainy");
        std::cout << "ObjectAddress:" << '\t';
        std::cout << &d1 << " " << &d2 << " " << &d3 << std::endl;
        std::cout << "YearAdddress: " << '\t';
        std::cout << d1.getAdd() << " " << d2.getAdd() << " " << d3.getAdd() << std::endl; // 同一个地址
        std::cout << "ObjectNum: " << '\t';
        std::cout << d1.getObjNum() << std::endl;
        std::cout << "d3:" << std::endl;
        d3.print();
    }
    /* 块结束，d1,d2,d3被销毁 */

    std::cout << "ObjectNum: " << '\t';
    std::cout << Date().getObjNum() - 1 << std::endl; // 匿名对象，借用它来显示剩余的对象数（不包括本身），程序结束后立刻被销毁
    return 0;
}