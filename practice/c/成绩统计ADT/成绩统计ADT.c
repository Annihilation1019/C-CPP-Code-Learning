// 有N个学生，每个学生的数据包括学号、姓名、3门课的成绩，从键盘输入N个学生的数据，要求打印出3门课的平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课成绩），要求使用链表
#include <stdio.h>
#include <stdlib.h>
#include "ADT_declare.h"

int main()
{
    INFO *head;
    init_list(&head);
    INFO *prv, *current;
    INFO *best = NULL; // 一个指向最高平均成绩信息的指针
    int N;
    printf("请输入需要录入的学生人数：");
    scanf("%d", &N);
    create_list(&head, &current, &prv, N);

    if (is_empty(&head))
    {
        printf("链表为空！");
    }
    else
    {
        traverse_list(&head, &best, &current);
    }
    printf("\n");
    print_best(&best);

    free_list(&head, &current);
    return 0;
}
