#include<stdio.h>
struct Date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

struct Info
{
    char name[20];
    char gender[10];
    struct Date date;
}info;
int main()
{
    struct Info info;
    struct Info *p = &info;
    printf("请输入姓名：");
    scanf("%s", info.name);
    printf("请输入性别：");
    scanf("%s", info.gender);
    printf("请输入出生年月日：");
    scanf("%d %d %d", &info.date.year, &info.date.month, &info.date.day);
    printf("\n数据录入完毕\n");
    printf("姓名：%s\n性别：%s\n出生日期：%d%d%d", info.name, info.gender, (*p).date.year, info.date.month, p->date.day);
    return 0;
}