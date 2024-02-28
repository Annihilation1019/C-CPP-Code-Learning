/* 阿里巴巴走进了装满宝藏的藏宝洞。藏宝洞里面有N<=100堆金币，第i堆金币的总重量和总价值分别是m和v（m>=1,v<=100）阿里巴巴有一个承重量T<=1000的背包但并不一定有办法将全部的金币都装进去。他想装走尽可能多价值的金币。所有金币都可以随意分割，分割完的金币重量价值比（也就是单位价格）不变。请问阿里巴巴最多可以拿走多少价值的金币？

第一行两个整数N,T。接下来N 行，每行两个整数,m,v。

一个实数表示答案，输出两位小数
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int weight;
    int value;
    double w;
} coin[110];

int cmp(const void *a, const void *b)
{
    struct Node *coin_a = (struct Node *)a;
    struct Node *coin_b = (struct Node *)b;
    return coin_b->w >= coin_a->w?1:-1;
}

int main()
{
    int N, T;
    double s = 0;
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &coin[i].weight, &coin[i].value);
        coin[i].w = (double)coin[i].value / coin[i].weight; // 计算性价比
    }
    qsort(coin, N, sizeof(coin[0]), cmp); // 快速排序
    for (int i = 0; i < N; i++)
    {
        if (T >= coin[i].weight)
        {
            T -= coin[i].weight;
            s += coin[i].value;
        }
        else
        {
            s += coin[i].w * T;
            break;
        }
    }
    printf("%.2f", s);
    return 0;
}