#pragma once

#include <stdbool.h>
typedef struct student_info
{
    int id;
    char name[10];
    int c_score, m_score, e_score;
    struct student_info *next;
} INFO;

// 初始化链表
void init_list(INFO **head);

// 创建链表
void create_list(INFO **head, INFO **current, INFO **prv, int N);

// 判断链表是否为空
bool is_empty(INFO **head);

// 遍历链表，并找到最高分的学生
void traverse_list(INFO **head, INFO **best, INFO **current);

// 打印最高分的学生信息
void print_best(INFO **best);

// 释放内存
void free_list(INFO **head, INFO **current);

#include "ADT_list.h"