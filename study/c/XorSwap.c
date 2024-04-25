#include <stdio.h>
int swap(int *a, int *b)
{
    if (*a != *b)
    {
        *a = *a ^ *b; // 对a和b的不同点做上标记1
        *b = *b ^ *a; // 根据标记修改b的值位a
        *a = *a ^ *b; // 根据标记修改a的值为b
    }                 // 相同的不改，不同的修改
    return 0;
}
int main()
{
    int a = 58;
    int b = 5;
    swap(&a, &b);
    printf("a=%d b=%d\n", a, b);
    return 0;
}
