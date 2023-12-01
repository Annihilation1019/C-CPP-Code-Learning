#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c, d, e;
    scanf("%d,%d,%d,%d,%d", &a, &b, &c, &d, &e);
    float av = (a + b + c + d + e) / 5.0;
    printf("%.1f\n", av); // 若想保留两位，则改为%.2f
    system("pause");
    return 0;
}