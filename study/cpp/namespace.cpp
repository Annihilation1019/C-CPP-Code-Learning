#include <iostream>
namespace Info1
{
    int id = 111;
    char name[20] = "a";
    void show(int a)
    {
        std::cout << "id: " << id << std::endl;
        std::cout << "name: " << name << std::endl;
    }
}
namespace Info2
{
    int id2 = 222;
    char name[20] = "b";
    void show()
    {
        std::cout << "id: " << id2 << std::endl;
        std::cout << "name: " << name << std::endl;
    }

    /* 名称空间可以嵌套 */
    namespace Info3
    {
        int id = 333;
        char name[20] = "c";
        void show()
        {
            std::cout << "id: " << id << std::endl;
            std::cout << "name: " << name << std::endl;
        }
        struct Info3
        {
            int age = 20;
            void show()
            {
                std::cout << "age: " << age << std::endl;
            }
        };
    }
}
namespace Info3
{
    void show(); // 这里并不是加到了Info2的Info3中，而是在全局名称空间中新创建了一个名称空间Info3
}

/* 可以在名称空间中使用using编译指令和using声明 */
namespace Info1
{
    using Info2::id2; // 使用using编译指令，将Info2中的id添加到Info1名称空间中
}

/* 给名称空间创建别名 */
namespace In = Info2; // Info4是Info2的别名，可以使用Info4来代替Info2

/* 未命名的名称空间：潜在作用域为从声明区域到文件结尾，由于不能使用using，具有内部链接，等效于给每个变量加上了static关键字 */
namespace
{
    int id = 444;
    char name[20] = "d";
    void show()
    {
        std::cout << "id: " << id << std::endl;
        std::cout << "name: " << name << std::endl;
    }
}

namespace
{
    int var;
}
// 等同于
static int var; // 具有内部链接，只能在当前文件中访问

/* 全局名称空间->对应于文件级声明区域，通常所说的全局变量现在都位于全局名称空间 */
int GlobalVar = 100; // 位于全局名称空间的全局变量
void show()
{
    std::cout << "GlobalVar: " << GlobalVar << std::endl;
}

using namespace Info1; // 使用名称空间，这里的using编译指令将Info1名称空间添加到全局名称空间中
int main()     
{
    /* using声明将名称添加到局部声明区域中，和其他局部变量一样，同名的全局变量将被名称空间的变量覆盖，而函数中已有的局部变量会覆盖名称空间的同名变量 */
    using namespace Info2; // 使用using指令时，更像是多次使用作用域解析运算符而不是多个using声明

    /* 注意，这两个不同名称空间的同名函数，引入时若函数特征标不同则会被视为重载函数 */
    using Info1::show; // 使用名称空间中的函数
    using Info2::show; // 使用名称空间中的函数

    Info1::show(1);
    Info2::Info3::show();
    Info2::Info3::Info3 test; // 在名称空间Info2::Info3中定义的结构体
    test.show();

    // Info3::show(); // Info3不明确，因为using编译指令使用了Info2在main()函数中
    ::Info3::show();      // 使用全局名称空间中的Info3
    Info2::Info3::show(); // 使用Info2中的Info3
    Info1::show(1);       // 使用名称空间中的函数
    show();               // 局部的show函数掩盖了全局的show函数

    In::id2 = 333; // 使用别名
    return 0;
}

namespace Info3 // 也可以直接void Info3::show()定义（存疑，这样似乎并不是正确写法，但能编译且运行正确？？？）
{
    void show()
    {
        std::cout << "可以在其他地方定义名称空间中的函数" << std::endl;
    }
}
