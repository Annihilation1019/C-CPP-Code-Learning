/*用*跳过scanf接收的数字*/
#include <stdio.h>
int main(void)
{
    int num;
    printf("Please enter three number:\n");
    scanf("%*d %*d %d", &num); // 读取一个字符并将其丢弃
    printf("The last number is %d\n", num);
    return 0;
}