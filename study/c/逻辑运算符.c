#include <stdio.h>
int main()
{//真值为1，假值为0
    printf("%d\n", 3 && 5);//若程序包含头文件<iso646.h>,则可以用and代替&&,用or代替||,用not代替!(并非所有键盘都有和美式键盘一样的符号，所以这个头文件不常用)
    printf("%d\n", 10 && 0);//逻辑运算符也是序列点
    printf("%d\n", 2 >= 3 || 10);
    printf("%d\n", 5 >= 5 || !0);
    return 0;
}//逻辑表达式的求值顺序是从左往右。一旦发现有使整个表达式为假的因子，就停止求值。这种求值顺序称为短路求值(short-circuit evaluation)