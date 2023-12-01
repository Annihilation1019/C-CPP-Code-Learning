// 有N个学生，每个学生的数据包括学号、姓名、3门课的成绩，从键盘输入N个学生的数据，要求打印出3门课的总平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课成绩）
#include <stdio.h>
typedef struct score_info
{
    unsigned int num;
    char name[20];
    int a, b, c;
} data, *info;
int main()
{

    int N = 0;
    printf("请输入学生个数:");
    scanf("%d", &N);
    data in[N];
    info p = in;
    for (size_t i = 0; i < N; i++) // 输入信息
    {
        printf("请输入第%d名学生的信息:", i + 1);
        scanf("%u%s%d%d%d", &(p + i)->num, &(p + i)->name, &(p + i)->a, &(p + i)->b, &(p + i)->c);
    }
    int av[N];
    for (size_t i = 0; i < N; i++) // 输出平均成绩
    {
        int sum = (p + i)->a + (p + i)->b + (p + i)->c;
        av[i] = sum / 3;
        printf("以下是第%d名学生的平均成绩:%d\n", i + 1, av[i]);
    }
    int max = av[0], sign = 0;
    for (size_t i = 0; i < N - 1; i++) // 求出最高平均成绩
    {
        if (av[i + 1] >= max)
        {
            max = av[i + 1];
            sign = i + 1;
        }
    }
    printf("最高成绩是%d\n", av[sign]);
    printf("最优成绩信息如下:%u %s %d %d %d", (p + sign)->num, (p + sign)->name, (p + sign)->a, (p + sign)->b, (p + sign)->c);
    return 0;
}