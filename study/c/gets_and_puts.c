#include <stdio.h>
int main()
{
    char str[10]; /*触发未定义行为具体会发生什么涉及很多实现细节，涉及编译器、操作系统，讨论它没有意义*/
    gets(str);    // 不安全
    puts(str);
    return 0;
}