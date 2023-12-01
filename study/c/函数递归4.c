//以二进制形式打印整数
#include <stdio.h>
void to_binary(unsigned long n);

int main()
{
    unsigned long n;
    printf("Please enter an integer (q to quit):\n");
    while (scanf("%lu", &n) == 1)
    {
        printf("Binary equivalent: ");
        to_binary(n);
        putchar('\n');
        printf("Please enter an integer (q to quit):\n");
    }
    printf("Done.\n");
    return 0;
}
void to_binary(unsigned long n)
{
    int r;
    r=n%2;
    if (n>=2)
    {
        to_binary(n / 2);
    }
    putchar(r == 0 ? '0' : '1');
    return;
}