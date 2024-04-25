#include <iostream>
using std::cout, std::endl;
class Book
{
private:
    std::string name_;   // 书名
    std::string author_; // 作者
    std::string press_;  // 出版社
    int ID_;             // 编号
    double price_;       // 价格
    int stock_;          // 库存
    bool isBorrowed_;    // 是否被借出
public:
    Book(std::string name, std::string author, int ID, double price, std::string press = "高等教育出版社", int stock = 0, bool isBorrowed = 0); // 声明一个含有默认参数的构造函数（参数名不要与类成员名相同）
    void print();
    Book() = default; // 重载一个默认构造函数
};

int main()
{
    /* 使用类构造函数 */
    Book book1 = Book("C++ Primer Plus", "Stephen Prata", 1, 128.0, "人民邮电出版社", 120); // 显式调用构造函数
    Book book2("C Primer Plus", "Stephen Prata", 2, 128.0, "人民邮电出版社");               // 隐式调用构造函数
    Book *book3 = new Book("C和指针", "Kenneth A. Reek", 3, 78.0);                          // 动态分配内存
    book1.print();
    book2.print();
    book3->print();

    /* 构造函数不能被对象调用 */
    Book arr[3] = {Book("高等数学", "空", 4, 69.2), Book("线性代数", "空", 5, 69.2), Book("概率论", "空", 6, 78.0)};                  // 数组初始化
    Book *p = new Book[3]{Book("微积分", "空", 4, 69.2), Book("电路分析基础", "空", 5, 69.2), Book("中国近代史纲要", "空", 6, 78.0)}; // 动态联编
    arr[0].print();
    (arr + 1)->print();
    p->print();

    /* 注意：如果未声明构造函数，C++将自动提供默认构造函数 */
    Book book4{}; // 默认构造函数
    /* 若提供了类构造函数，而未提供默认构造函数以下声明将出错，必须自己提供默认构造函数且必须没有参数或所有参数有默认值 */
    // Book book5; // 错误：未提供默认构造函数
    return 0;
}

Book::Book(std::string name, std::string author, int ID, double price, std::string press, int stock, bool isBorrowed)
{
    name_ = name;
    author_ = author;
    ID_ = ID;
    price_ = price;
    press_ = press;
    stock_ = stock;
    isBorrowed_ = isBorrowed;
}

void Book::print()
{
    cout << "书名：" << name_ << endl;
    cout << "作者：" << author_ << endl;
    cout << "出版社：" << press_ << endl;
    cout << "编号：" << ID_ << endl;
    cout << "价格：" << price_ << endl;
    cout << "库存：" << stock_ << endl;
    if (isBorrowed_)
    {
        cout << "已经借出" << endl;
    }
    else
    {
        cout << "未借出" << endl;
    }
}