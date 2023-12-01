/*目前正是甲流盛行时期，为了更好地进行分流治疗，医院在挂号时要求对病人的体温和咳嗽情况进行检查，对于体温超过37.5度（含等于37.5度）并且咳嗽的病人初步判定为甲流病人（初筛）。现需要统计某天前来挂号就诊的病人中有多少人被初筛为甲流病人。
第一行是某天前来挂号就诊的病人数n。（n < 200）其后有n行，每行是病人的信息，包括三个信息：姓名（字符串，不含空格，最多8个字符）、体温（float）、是否咳嗽（整数，1表示咳嗽，0表示不咳嗽）。每行三个信息之间以一个空格分开。*/
#include <stdio.h>
typedef struct patient
{
    char name[9];
    float tem;
    int cough;
} patient, *pa;

int main()
{
    short n, j = 0;
    scanf("%hd", &n);
    patient info[n];
    pa pinfo = info;
    for (short i = 0; i < n; i++) // 录入信息
    {
        scanf("%s%f%d", (pinfo + i)->name, &(pinfo + i)->tem, &(pinfo + i)->cough);
    }
    for (short i = 0; i < n; i++)
    {
        if (((pinfo + i)->tem) >= 37.5 && (pinfo + i)->cough == 1)
        {
            printf("%s\n", (pinfo + i)->name);
            j++;
        }
    }
    printf("%d\n", j);
    return 0;
}
