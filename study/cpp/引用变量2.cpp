#include <iostream>
using namespace std;
struct student_info
{
    string name;
    int id;
    int age;
    int score;
};

student_info &change(student_info &s);
void display(const student_info &s);
student_info &find(student_info *sinfo, int n, int id);

// 类设计的语义常常要求使用引用，这是C++新增这项特性的主要原因。因此传递类对象参数的标准方式是按引用传递。这样可以避免复制对象，提高效率。

int main()
{
    student_info sinfo[5] = {
        {"张三", 1, 18, 100},
        {"李四", 2, 19, 99},
        {"王五", 3, 20, 98},
        {"赵六", 4, 21, 97},
        {"孙七", 5, 22, 96}};
    display(find(sinfo, 5, 3));
    display(change(find(sinfo, 5, 3)));
    return 0;
}

student_info &change(student_info &s)
{
    s.name = "王五";
    s.id = 6;
    s.age = 23;
    s.score = 95;
    return s;
}
void display(const student_info &s)
{
    cout << "Name: " << s.name << '\n';
    cout << "ID: " << s.id << '\n';
    cout << "Age: " << s.age << '\n';
    cout << "Score: " << s.score << '\n'; //
}
student_info &find(student_info *sinfo, int n, int id) // 返回引用时，要求返回的变量在函数结束后仍然存在
{
    for (int i = 0; i < n; i++)
    {
        if (sinfo[i].id == id)
            return sinfo[i];
    }
    return sinfo[0];
}
