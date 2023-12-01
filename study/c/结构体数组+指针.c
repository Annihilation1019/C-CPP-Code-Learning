#include <stdio.h>
#include<stdlib.h>
struct address
{
    char name[30];     /*姓名，字符数组作为结构体中的成员*/
    char street[40];   /*街道*/
    unsigned long tel; /*电话，无符号长整型作为结构体中的成员*/
    unsigned long zip; /*邮政编码*/
};
int main()
{
    struct address a[3];
    struct address *p = a;
    for (size_t i = 0; i < 3; i++)
    {
        printf("请输入第%d个人的姓名，居住地，电话，邮政编码：", i + 1);
        scanf("%s %s %u %u", &(p + i)->name, &(p + i)->street, &(p + i)->tel, &(p + i)->zip);
    }
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s\n %s\n %u\n %u\n", (*p).name, (p + i)->street, (p + i)->tel, (p + i)->zip);
    }
    system("pause");
    return 0;
}