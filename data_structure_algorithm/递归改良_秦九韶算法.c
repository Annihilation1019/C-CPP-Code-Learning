// 时间复杂度O(n) 空间复杂度O(n)
#include <stdio.h>
// 将5*4*3*2*1+4*3*2*1+3*2*1+2*1+1=((((5+1)*4+1)*3+1)*2+1)*1
int i = 0;
long long Qinjiushao_algorithm(int n, long long acc)
{
    i++;
    if (n == 0)//n相当于计数器，当n=0时，递归结束
    {
        return acc;
    }
    return Qinjiushao_algorithm(n - 1, (acc + 1) * n);
}
long long sum(int n)
{
    return Qinjiushao_algorithm(n, 0);
}
int main()
{
    int n = 0;
    printf("请输入一个正整数：");
    scanf("%d", &n);
    printf("%lld", sum(n));
    printf("\n函数被调用了%d次", i);
}