#include <iostream>
#include <array>
using namespace std;
const int SEASON = 4;
// array并非只能存储基本数据类型，它还可以存储类对象
const array<string, SEASON> Snames = {"Spring", "Summer", "Fall", "Winter"};

void fill(array<double, SEASON> *pa);
void show(array<double, SEASON> da);
int main()
{
    array<double, SEASON> expenses;
    fill(&expenses); // 传入指针
    show(expenses);  // 传入对象
    return 0;
}

void fill(array<double, SEASON> *pa)
{
    for (int i = 0; i < SEASON; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i]; // 注意这里的写法
    }
}
void show(array<double, SEASON> da)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < SEASON; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}