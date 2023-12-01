#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = {"abc"};
    printf("%d\n", sizeof(str));
    printf("%d", strlen(str));
    return 0;
}