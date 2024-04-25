#include <iostream>
using namespace std;
enum Color : unsigned char // 可以自己指定类型
{
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    INDIGO,
    VIOLET
};
int main()
{
    cout << "Enter a color code(0-6): ";
    int code;
    cin >> code;
    switch (code) // int值和枚举类型比较时，将枚举提升为int
    {
    case RED: // case标签必须是整型常量表达式，包括char
        cout << "Her lips were red." << endl;
        break;
    case ORANGE:
        cout << "Her hair was orange." << endl;
        break;
    case YELLOW:
        cout << "Her shoes were yellow." << endl;
        break;
    case GREEN:
        cout << "Her nails were green." << endl;
        break;
    case BLUE:
        cout << "Her sweatsuit was blue." << endl;
        break;
    case INDIGO:
        cout << "Her eyes were indigo." << endl;
        break;
    case VIOLET:
        cout << "She wrote her name was Violet." << endl;
        break;
    default:
        cout << "You entered a wrong code!" << endl;
    }
    return 0;
}