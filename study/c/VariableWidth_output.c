/*使用可变宽度输出字段*/
#include <stdio.h>
int main(void)
{
    unsigned width, precision;
    int number = 256;
    double weight = 25.5;
    printf("Please input number's width:\n");
    scanf("%d", &width);
    printf("The number is: %*d\n", width, number);
    printf("Then please input width and precision:\n");
    scanf("%d %d", &width, &precision);
    printf("Weight = %*.*f\n", width, precision, weight);
    return 0;
}