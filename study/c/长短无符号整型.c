#include <stdio.h>
int main()
{
    unsigned int un = 3000000000; // int 为 32 位和 short 为 16 位的系统
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;
    printf("un=%u and not %d\n", un, un);
    printf("end=%#hx and %d\n", end, end);
    printf("big=%ld and not %hd\n", big, big);//使用h修饰符可以显示较大整数被截断成short类型值的情况。
    printf("verybig=%lld and not %ld\n", verybig, verybig);
    return 0;
} // 输入八进制或十六进制数时要加上前缀0或0x
