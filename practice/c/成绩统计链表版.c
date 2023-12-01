// 有N个学生，每个学生的数据包括学号、姓名、3门课的成绩，从键盘输入N个学生的数据，要求打印出3门课的平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课成绩），要求使用链表
#include <stdio.h>
#include <stdlib.h>

typedef struct student_info
{
    int id;
    char name[10];
    int c_score, m_score, e_score;
    struct student_info *next;
} INFO;
int main()
{

    INFO *head = NULL;
    INFO *prv, *current;
    INFO *best=NULL; // 一个指向最高平均成绩信息的指针
    int N;
    printf("请输入需要录入的学生人数：");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        current = (INFO *)malloc(sizeof(INFO));
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            prv->next = current;
        }
        current->next = NULL;
        printf("请输入学号：");
        scanf("%d", &current->id);
        printf("请输入姓名：");
        scanf("%s", current->name);
        printf("请输入各科成绩：");
        scanf("%d%d%d", &current->c_score, &current->m_score, &current->e_score);
        prv = current;
        while (getchar() != '\n')
        {
            continue;
        }
    }

    if (head == NULL)
    {
        printf("链表为空！");
    }
    else
    {

        current = head;
        int average = 0, max = 0;
        while (current != NULL)
        {
            average = (current->c_score + current->m_score + current->e_score) / 3;
            printf("\n学号：%d\t姓名：%s\t平均成绩：%d", current->id, current->name, average);
            if (max <= average)
            {
                max = average;
                best = current;
            }
            current = current->next;
        }
    }
    printf("\n");
    printf("最高分学生信息如下：\n");
    printf("学号：%d\t姓名：%s\t各科成绩：%d %d %d", best->id, best->name, best->c_score, best->m_score, best->e_score);

    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
    }
    printf("\nsuccess!");
    return 0;
}
