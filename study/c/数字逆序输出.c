#include <stdio.h>
int main()
{
    float a[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &a[i]);
    }
    for (int i = 9; i >= 0; i--)
    {
        printf("%.2f ", a[i]);
    }
    return 0;
}