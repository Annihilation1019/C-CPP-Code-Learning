#include <stdio.h>
int main()
{
    unsigned int age = 0;
    printf("请输入年龄：");
    scanf("%d", &age);
    if (age < 18)
    {
        printf("少年\n");
    }
    else if (age >= 18 && age < 30)
    {
        printf("青年\n");
    }
    else if (age >= 30 && age < 50)
    {
        printf("中年\n");
    }
    else if (age >= 50 && age < 80)
    {
        printf("老年\n");
    }
    else
    {
        printf("老寿星\n");
    }
}