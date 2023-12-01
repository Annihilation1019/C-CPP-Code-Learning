#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand((unsigned int)time(0));
    do
    {
        while (getchar() != '\n')
        {
            continue;
        }
        printf("你投出的是%d点\n", rand() % 6 + 1);
        printf("按q退出，按其他键继续\n");
    } while (getchar() != 'q');
}