/*津津的零花钱一直都是自己管理。每个月的月初妈妈给津津 $300$ 元钱，津津会预算这个月的花销，并且总能做到实际花销和预算的相同。
为了让津津学习如何储蓄，妈妈提出，津津可以随时把整百的钱存在她那里，到了年末她会加上 $20\%$ 还给津津。因此津津制定了一个储蓄计划：每个月的月初，在得到妈妈给的零花钱后，如果她预计到这个月的月末手中还会有多于 $100$ 元或恰好 $100$ 元，她就会把整百的钱存在妈妈那里，剩余的钱留在自己手中。
例如 $11$月初津津手中还有 $83$ 元，妈妈给了津津 $300$ 元。津津预计$11$月的花销是 $180$ 元，那么她就会在妈妈那里存 $200$ 元，自己留下 $183$ 元。到了 $11$ 月月末，津津手中会剩下 $3$ 元钱。
津津发现这个储蓄计划的主要风险是，存在妈妈那里的钱在年末之前不能取出。有可能在某个月的月初，津津手中的钱加上这个月妈妈给的钱，不够这个月的原定预算。如果出现这种情况，津津将不得不在这个月省吃俭用，压缩预算。
现在请你根据 $2004$ 年 $1$ 月到 $12$ 月每个月津津的预算，判断会不会出现这种情况。如果不会，计算到 $2004$ 年年末，妈妈将津津平常存的钱加上 $20\%$ 还给津津之后，津津手中会有多少钱。*/
#include <stdio.h>
#define MONTH 12
void initialization(int *, int);
int main()
{
    int budget[MONTH], remain = 0, savings = 0, sav_per_month = 0;
    initialization(budget, MONTH); // 对数组初始化
    for (int i = 0; i < MONTH; i++)
    {
        if (budget[i] > remain + 300)
        {
            printf("%d", (i + 1) * (-1));
            return 0;
        }
        savings += sav_per_month = (300 + remain - budget[i]) / 100 * 100;
        remain = 300 + remain - budget[i] - sav_per_month;
    }
    printf("%d", (int)(savings * 1.2 + remain));
    return 0;
}

void initialization(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        scanf("%d", arr + i);
    }
}