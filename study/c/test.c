// this is a c program
#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d", &a);
    b = a * 2;
    c = a * 3;
    printf("b=%d\n", b);
    printf("c=%d\n", c);
    getchar(); // 吸收回车
    return 0;
}