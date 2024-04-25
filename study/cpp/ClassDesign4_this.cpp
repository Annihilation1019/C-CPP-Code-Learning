#include <iostream>
class Computer
{
private:
    std::string brand;
    float price;
    int cpu_core;
    int memory_GB;
    int disk_GB;

public:
    Computer(std::string brand, float price, int cpu_core, int memory_GB, int disk_GB);
    ~Computer() = default;
    Computer &compare_price(Computer &other);
    void print() const { std::cout << "Brand: " << brand << " Price: " << price << " CPU core: " << cpu_core << " Memory: " << memory_GB << " Disk: " << disk_GB << std::endl; }
    void set_price(float price) { this->price = price; }
};

int main()
{
    Computer computer1("Dell", 5000, 4, 8, 256);
    Computer computer2("Lenovo", 4000, 4, 8, 256);
    Computer &expensive = computer1.compare_price(computer2); // expensive作为了一个常量引用，所以不能修改其值，是computer1的别名。computer1.compare_price(computer2)中的this指针指向computer1
    std::cout << "The more expensive computer is ";
    expensive.print();
    std::cout << std::endl;
    expensive.set_price(6000); // 通过expensive修改computer1的price
    computer1.print();
    return 0;
}

Computer::Computer(std::string brand, float price, int cpu_core, int memory_GB, int disk_GB)
{
    /* this指针指向调用该方法的对象 */
    this->brand = brand;
    this->price = price;
    this->cpu_core = cpu_core;
    this->memory_GB = memory_GB;
    this->disk_GB = disk_GB;
}

Computer &Computer::compare_price(Computer &other)
{
    return this->price > other.price ? *this : other;
}