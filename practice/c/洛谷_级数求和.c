// 已知：Sn=1+1/2+1/3+…+1/n，显然对于任意一个整数K，当n足够大的时候，Sn>K。现在给出一个整数K（1<=K<=15），要求计算出一个最小的n；使得Sn>K。
#include <stdio.h>
int main()
{
    double Sn = 0;
    int K, n = 1;
    scanf("%d", &K);
    do
    {
        double i = 1.0 / n;
        Sn += i;
        n++;
    } while (Sn <= K);
    printf("%d", n - 1);
    return 0;
}