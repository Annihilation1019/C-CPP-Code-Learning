#include <iostream>
struct student_info
{
    int id;
    char name[20];
    int age;
};
int main()
{
    using namespace std;
    student_info *p = new student_info[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "请输入第" << i + 1 << "个学生的信息：";
        cin >> p[i].id >> p[i].name >> p[i].age;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "第" << i + 1 << "个学生的信息是：";
        cout << p[i].id << " " << p[i].name << " " << p[i].age << endl;
    }
    delete[] p;
    return 0;
}