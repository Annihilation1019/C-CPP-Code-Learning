#include<stdio.h>
int main()
{
    int a[10] = {0};
    int *p = a;//数组中a相当于&a[0]
    for (size_t i = 0; i < 10; i++)
    {
        *(p+i)=i;
    }
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d",*(p+i));
    }
    printf("\n");
    printf("%x\n", *(a+2));
    printf("%x", p+2);
    return 0;
}