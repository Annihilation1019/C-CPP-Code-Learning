#include <iostream> //iostream必须隐式包含所有与c流有关的内容或者头文件，所以这里只需要包含iostream即可，这是标准规定的
int main()
{
    using namespace std; //写法一：使std名称空间中的所有名称都可用

    using std::cout;
    using std::endl;//写法二：只使所需的名称可用

    cout << "Hello World!" << endl;//如果没有上面两行，这里就要写成std::cout，因为cout是std的成员
    printf("%f\n", 3.14);
    cout << 3.14 << endl;//cout智能行为源自OOP特性

    int carrots;
    cin >> carrots;
    cout << "now you have " << carrots << " carrots." << endl;

    //以十六进制或八进制输入或输出
    int chest = 42;
    cout << hex;//如果是浮点型数据，则需要使用hexfloat(不仅限于float，还有double等)
    cout << "chest =0x" << chest << endl;
    cout << oct;//不会在屏幕上显示任何内容，只是修改cout显示整数的方式。控制符hex实际上是一条消息，告诉cout采取何种行为
    cout << "chest =0" << chest << endl;

    //使用成员函数cout.put()来输出单个字符
    char ch = 'M';
    int i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);//作用类似于C语言中的putchar()函数
    cout.put('!');
    cout << endl << "Done" << endl;

    //使用cout.setf()来控制浮点数的显示方式
    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float million = 1.0e6;
    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout.setf(ios_base::fixed, ios_base::floatfield);//设置为定点表示法，而不是默认的浮点表示法
    cout << million * tub << endl;
    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;
    return 0;
}