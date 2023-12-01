#include <stdio.h>
int main()
{
    int a = 4;
    int *p = &a; //&别忘了
    printf("%p %d %#x %#x %d\n", p, *p, &a, &p, a);
    *p = 2023;
    printf("%p %d %#x %#x %d\n", p, *p, &a, &p, a);
    a = 12;
    printf("%p %d %#x %#x %d\n", p, *p, &a, &p, a);
    return 0;
}