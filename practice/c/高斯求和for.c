#include <stdio.h>
int main()
{
    int sum = 0;
    for (int i = 0; i < 101; i++)
    {
        sum = sum + i;
    }
    printf("%d", sum);
    return 0;
}