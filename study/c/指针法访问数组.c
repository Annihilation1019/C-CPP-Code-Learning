#include <stdio.h>
int main()
{
    int i;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};//a是一个指针常量，不能自加
    int *p = a; /*等价于int *p=&a[0];*/
    for (i = 0; i < 10; i++)
    {
        printf("P Value:%d   a Value :%d\n", *(p++), *(a + i));//a是常量不能自加，指针是一个变量，可以自加
    }
    printf("\n");
    return 0;
}
