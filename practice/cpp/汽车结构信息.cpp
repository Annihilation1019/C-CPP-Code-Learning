#include <iostream>
#include <string>
using namespace std;
struct Car
{
    char manufacturer[20];
    int year;
};

int main()
{
    int cars;
    cout << "How many cars do you wish to catalog? ";
    cin >> cars;
    cin.ignore();
    Car *car_info = new Car[cars];
    for (int i = 0; i < cars; i++)
    {
        cout << "Car #" << i + 1 << ": " << endl
             << "Please enter the make:";
        cin.getline(car_info[i].manufacturer, 20);
        cout << "Please enter the year made: ";
        cin >> car_info[i].year;
        cin.ignore();
    }

    cout << "Here is your collection:" << endl;
    for (int i = 0; i < cars; i++)
    {
        cout << car_info[i].manufacturer << " " << car_info[i].year << endl;
    }
    delete[] car_info;
    return 0;
}