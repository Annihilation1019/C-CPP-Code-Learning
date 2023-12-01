// 给年份year，定义一个宏，以判别该年份是否闰年。提示：宏名可以定义为LEAP_YEAR，形参为y，既定义宏的形式为 #define LEAP_YEAR(y) （读者设计的字符串）
#include <stdio.h>
#define LEAP_YEAR(y) (y % 4 == 0 && y % 100 != 0 || y % 400 == 0 ? 'L' : 'N')
int main()
{
    int y = 0;
    scanf("%d", &y);
    printf("%c", LEAP_YEAR(y));
}