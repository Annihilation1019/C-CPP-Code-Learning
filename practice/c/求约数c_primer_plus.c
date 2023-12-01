// 输入一个整数，打印出所有因数，如果是素数，打印出是素数，要求使用if嵌套语句
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    unsigned long num; // 待检测的数
    unsigned long div; // 可能的约数
    bool isPrime;      // 素数标记
    printf("Please enter an integer for analysis; ");
    printf("Enter q to quit.\n");
    while (scanf("%lu", &num) == 1) // 输入的是整数
    {
        for (div = 2, isPrime = true; (div * div) <= num; div++) // 从2开始，直到div*div大于num
        {
            if (num % div == 0)
            {
                if ((div * div) != num)
                {
                    printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
                }
                else
                {
                    printf("%lu is divisible by %lu.\n", num, div);
                }
                isPrime = false; // 该数不是素数
            }
        }
        if (isPrime)
        {
            printf("%lu is prime.\n", num);
        }
        printf("Please enter another integer for analysis;");
        printf("Enter q to quit.\n");
    }
    printf("Bye.\n");
    return 0;
}