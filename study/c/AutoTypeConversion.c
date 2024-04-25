#include <stdio.h>
int main(void)
{
    // char和short类型出现在表达式中时，会被自动转换为int类型，float类型出现在表达式中时，会被自动转换为double类型。当把一种类型的值赋给另一种类型的变量时，赋值号两边的类型会被转换为等号左边的类型。在混合类型的运算中，较小类型会被转换成较大类型。在赋值时，较大类型会被转换成较小类型，但是会丢失精度。
    char ch;
    int i;
    float fl;

    fl = i = ch = 'C';                          //%c对应字符，%d对应整数，%f对应浮点数
    printf("ch=%c,i=%d,fl=%2.2f\n", ch, i, fl); 
    ch += 1;
    i = fl + 2 * ch;   // ch是字符，所以加减乘除都是对应ASCII码
    fl = 2.0 * ch + i; // 为了做加法，i被转换为浮点数
    printf("ch=%c,i=%d,fl=%2.2f\n", ch, i, fl);
    ch = 1107; // 被求模截断 1107%256=83
    printf("Now ch=%c\n", ch);
    ch = 80.89; // 被转换为字符P，小数点后截断
    printf("Now ch=%c\n", ch);

    return 0;
}