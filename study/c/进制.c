#include <stdio.h>
int main()
{
    int x = 100;
    printf("x(10) = %d\nx(8)=%o\nx(16)=%x\n", x, x, x);
    printf("x(10) = %d\nx(8)=%#o\nx(16)=%#x", x, x, x); //%#o表示八进制，%#x表示十六进制
    return 0;
}