#define MAX 100                 // 将 MAX 这个标识符和 100 这个数字关联起来
#define REG register            // 为 register 这个关键字，创建一个简短的名字REG
#define STR "test_string"       // 用 STR 这样一个名字来代替 test_string 这样一个字符串
#define fun(a, b) a > b ? a : b // #define定义标识符的本质就是替换
#include <stdio.h>
int main()
{
    REG int a = MAX; // 这里的 reg 被解释成 register关键字，MAX 被解释成 100
    printf("%d\n", a);
    printf("%s\n", STR);
    printf("%d", fun(3, 5));
    return 0;
} // 符号常量通常大写，以便于和变量区分，但不是必须的，只是一种约定俗成的规范，不遵守也不会报错，但是不建议这么做，因为这样会让人误以为这是一个变量，而不是一个常量。
  // 使用define是一个良好的习惯，可以方便地修改代码，而且不会出现因为修改了一个变量的值而导致的各种错误，但是也不要滥用，因为define只是一个简单的替换，不会进行类型检查，所以在使用的时候要注意。