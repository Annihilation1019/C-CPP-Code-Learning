#include <iostream>
struct student_info
{
    int id;
    char name[20];
    int age;
};
int main()
{
    student_info info1, info2, info3;                              // 定义三个结构体变量
    info1.id = 100001;                                             // 使用成员运算符访问成员
    student_info *p = &info2;                                      // 定义指向结构体的指针
    p->id = 100002;                                                // 使用指针访问成员
    student_info info_arr[3];                                      // 定义结构体数组
    info_arr[0].id = 100003;                                       // 使用下标访问成员
    (info_arr + 1)->age = 20;                                      // 使用指针访问成员
    const student_info *pointer_arr[3] = {&info1, &info2, &info3}; // 定义指针数组
    std::cout << pointer_arr[0]->id << std::endl;                  // 使用指针访问成员
    const student_info **ppa = pointer_arr;                        // 定义指向指针数组的指针
    std::cout << (*ppa)->id << std::endl;                          // 使用指针访问成员
    auto ppa_auto = pointer_arr;                                   // 使用auto关键字(C++11)定义指向指针数组的指针，注意这里的类型是const student_info **
    std::cout << (*ppa_auto)->id << std::endl;
    std::cout << ppa_auto[0]->id << std::endl;                     // 使用指针访问成员
    return 0;
}