#include <stdio.h>
int main()
{
    int a, b;
    char c;
    scanf("%d%d%c", &a, &b, &c); // scanf()读取字符型数据时会将空白读入，所以需要在%c前加一个空格，或者在%c前加一个getchar()语句
    printf("%d%d%c", a, b, c);   //%5d可以限定输入长度
    return 0;
} /*输入:5 4z
    输出:54z
    输入:5 4 z,空白被%c读入，需要额外注意
    输出:54 */