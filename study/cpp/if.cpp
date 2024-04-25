#include <iostream>
int main()
{
    char ch;

    std::cout << "Type, and I shall repeat.\n";
    std::cin.get(ch);
    while (ch != '.')
    {
        if (ch == '\n')
            std::cout << ch;
        else
            std::cout << ++ch;// ch + 1 会将字符转换为整数，然后加 1，输出为整数（整型提升）
        std::cin.get(ch);
    }

    std::cout << "\nPlease excuse the slight confusion.\n";
    return 0;
}