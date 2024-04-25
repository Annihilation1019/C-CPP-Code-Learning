#include <iostream>
class Volume
{
    int length_;
    int width_;
    int height_;
    int ***staff;

public:
    Volume(int length = 0, int width = 0, int height = 0); // 声明一个含有默认参数的构造函数
    int getVolume() { return length_ * width_ * height_; }
    ~Volume(); // 析构函数，不接受参数，没有返回值，不能重载，用于释放资源（如果对象没有使用new，可以将它编写为不执行任何操作的函数）
    void setVal(int i, int j, int k, int val) { staff[i][j][k] = val; }
    int getVal(int i, int j, int k) { return staff[i][j][k]; }

    /* const成员函数 */
    void show() const;
};

int main()
{
    Volume volume(3, 4, 5);
    std::cout << volume.getVolume() << std::endl;
    volume.setVal(1, 2, 3, 4);
    std::cout << volume.getVal(1, 2, 3) << std::endl;
    Volume one = Volume(1, 2, 3); // 临时对象被创建，然后被销毁，立即调用析构函数

    /* C++11列表初始化，只要花括号内提供与某个构造函数列表匹配的内容 */
    Volume two{1, 2, 3};
    Volume three = {1, 2, 3};

    const Volume four = Volume{1, 2, 3};
    four.show(); // const对象不能调用非const成员函数（如果show未被声明为const类型）
    
    /* 存在只有一个参数的构造函数，可以使用赋值语句，它会被视为隐式调用了构造函数 */
    Volume five = 4; // 将调用Volume(4, 0, 0)
    five.show();
    return 0;
}

Volume::Volume(int length, int width, int height)
{
    length_ = length;
    width_ = width;
    height_ = height;
    staff = new int **[length_];
    for (int i = 0; i < length_; i++)
    {
        staff[i] = new int *[width_];
        for (int j = 0; j < width_; j++)
        {
            staff[i][j] = new int[height_];
        }
    }
}

Volume::~Volume()
{
    for (int i = 0; i < length_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            delete[] staff[i][j];
        }
        delete[] staff[i];
    }
    delete[] staff;
    std::cout << "OK" << std::endl;
}

void Volume::show() const
{
    // length_ = 10; // 错误，const成员函数不能修改成员变量
    std::cout << "length: " << length_ << " width: " << width_ << " height: " << height_ << std::endl;
}