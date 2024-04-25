// 时间复杂度O(1)，空间复杂度O(n)
#include <stdio.h>
enum grocery // 建立映射关系
{
    apple,
    banana,
    orange,
    pear,
    grape,
    watermelon,
};
int main()
{
    float price[6] = {3.0, 2.5, 4.1, 2.0, 1.5, 5.0};
    char name[20];
    scanf("%s", name);
    printf("%.1f\n", price[name[0] - 'a']);
}