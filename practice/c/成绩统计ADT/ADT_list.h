#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "ADT_declare.h"
void init_list(INFO **head)
{
    *head = NULL;
}

void create_list(INFO **head, INFO **current, INFO **prv, int N)
{
    for (int i = 0; i < N; i++)
    {
        *current = (INFO *)malloc(sizeof(INFO));
        if (*head == NULL)
        {
            *head = *current;
        }
        else
        {
            (*prv)->next = *current;
        }
        (*current)->next = NULL;
        printf("请输入学号：");
        scanf("%d", &(*current)->id);
        printf("请输入姓名：");
        scanf("%s", &(*current)->name);
        printf("请输入各科成绩：");
        scanf("%d%d%d", &(*current)->c_score, &(*current)->m_score, &(*current)->e_score);
        *prv = *current;
        while (getchar() != '\n')
        {
            continue;
        }
    }
}

bool is_empty(INFO **head)
{
    if (*head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void traverse_list(INFO **head, INFO **best, INFO **current)
{
    *current = *head;
    int average = 0, max = 0;
    while (*current != NULL)
    {
        average = ((*current)->c_score + (*current)->m_score + (*current)->e_score) / 3;
        printf("\n学号：%d\t姓名：%s\t平均成绩：%d", (*current)->id, (*current)->name, average);
        if (max <= average)
        {
            max = average;
            *best = *current;
        }
        *current = (*current)->next;
    }
}

void print_best(INFO **best)
{
    printf("最高分学生信息如下：\n");
    printf("学号：%d\t姓名：%s\t各科成绩：%d %d %d", (*best)->id, (*best)->name, (*best)->c_score, (*best)->m_score, (*best)->e_score);
}

void free_list(INFO **head, INFO **current)
{
    *current = *head;
    while (*current != NULL)
    {
        *head = (*current)->next;
        free(*current);
        *current = *head;
    }
    printf("\nsuccess!");
}