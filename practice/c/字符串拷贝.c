// 有一字符串，包含n个字符。写一函数，将此字符串中从第m个字符开始的全部字符复制成为另一个字符串。
#include <stdio.h>
int main()
{
    unsigned n = 0, m = 0;
    scanf("%d", &n);
    char a[n];
    scanf("%s", a);
    scanf("%d", &m);
    printf("%s", a + m - 1);
    return 0;
}