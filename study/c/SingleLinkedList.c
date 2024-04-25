#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 20
typedef struct student
{ // 数据域
    int id;
    char name[NAME];
    int score;
    // 指针域
    struct student *next; // 指向下一个结点的指针
} STU;                    // 链表的结点

int main()
{
    // 创建链表
    STU *head = NULL;    // 头指针
    STU *prev, *current; // 临时指针
    do
    {
        // 1.使用malloc函数申请一个结点的内存空间
        current = (STU *)malloc(sizeof(STU));
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            prev->next = current;
        }
        // 2.给结点的数据域赋值
        current->next = NULL; // 新结点的指针域指向空，表示目前是最后一个结点
        printf("请输入学号：");
        scanf("%d", &current->id);
        printf("请输入姓名：");
        scanf("%s", current->name);
        printf("请输入成绩：");
        scanf("%d", &current->score);
        // 3.将新结点的地址赋值给prev指针
        prev = current;
        while (getchar() != '\n')
        {
            continue;
        }
        printf("是否继续输入？(y/n)");
        if (getchar() == 'n')
        {
            break;
        }
    } while (1);
    // 遍历链表
    if (head == NULL)
    {
        printf("链表为空！\n");
    }
    else
    {
        current = head; // 从头结点开始遍历
        while (current != NULL)
        {
            printf("学号：%d\t姓名：%s\t成绩：%d\n", current->id, current->name, current->score);
            current = current->next;
        }
    }
    // 释放链表
    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
    } // 令头指针指向下一个结点，释放当前结点，直到头指针为空
    return 0;
}