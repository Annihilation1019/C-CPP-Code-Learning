#include <iostream>
#include <windows.h>
class Book
{
private:
    std::string name;
    float price;
    int pages;

public:
    Book(std::string name = " ", float price = 0, int pages = 0);
    ~Book() = default;
    Book &top_price(Book &other) { return this->price >= other.price ? *this : other; }
    void print() const
    {
        std::cout << "Name: " << name << " Price: " << price << " Pages: " << pages << std::endl;
    };
};
int main()
{
    /* 初始化对象数组的方案：首先使用默认构造函数创建数组元素，然后花括号中的构造函数将创建临时对象，然后临时对象中的元素将复制到相应元素中。 */
    /* 因此，这个类必须有默认构造函数或者构造函数全部参数有默认值 */
    Book store[5]{Book("高等数学", 58.0, 200), Book("线性代数", 45.2, 125)}; // 不能使用初始化器  余下三个元素将使用默认构造函数
    for (int i = 0; i < 5; i++)
    {
        store[i].print();
    }
    const Book expensive = store[0].top_price(store[1]);
    std::cout << "The most expensive book is: ";
    expensive.print();
    return 0;
}

Book::Book(std::string name, float price, int pages)
{
    this->name = name;
    this->price = price;
    this->pages = pages;
}