#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct List
{
    ElemType data;
    struct List *next;
} LinkList;

/**
 * @brief 链表初始化
 * @param n 创建链表长度
 * @return LinkList* 返回链表头指针
 */
LinkList *LinkListInit(int n);

/**
 * @brief 修改链表中的元素
 * @param List 链表头指针
 * @param n 修改的位置
 * @param dat 修改为的数据
 * @return void
 */
void LinkListChange(LinkList *List, int n, ElemType dat);

/**
 * @brief 删除链表中的元素
 * @param List 链表头指针
 * @param n 删除的位置（表头除外）
 * @return void
 */
void LinkListDelete(LinkList *List, int n);

/**
 * @brief 打印链表
 * @param List 链表头指针
 * @return void
 */
void LinkListPrint(LinkList *List);

/**
 * @brief 在链表中插入元素
 * @param List 链表头指针
 * @param n 插入到第n个位置后面
 * @return void
 */
void LinkListInsert(LinkList *List, int n);

/**
 * @brief 销毁链表
 * @param List 链表头指针
 * @return void
 */
void LinkListDestroy(LinkList *List);

int main()
{
    LinkList *List = LinkListInit(5); // 创建一个长度为5的链表
    LinkListPrint(List);
    LinkListChange(List, 2, 8); // 修改第二个位置为8
    LinkListPrint(List);
    LinkListInsert(List, 4); // 在第四个位置后面插入一个元素
    LinkListPrint(List);
    LinkListDelete(List, 5); // 删除第五个位置
    LinkListPrint(List);

    LinkListDestroy(List); // 销毁链表
    return 0;
}

LinkList *LinkListInit(int n)
{
    LinkList *head = NULL, *current, *prev;

    for (int i = 0; i < n; i++)
    {
        current = (LinkList *)malloc(sizeof(LinkList));
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            prev->next = current;
        }
        scanf("%d", &(current->data));
        current->next = NULL;
        prev = current;
    }
    return head;
}

void LinkListChange(LinkList *List, int n, ElemType dat)
{
    LinkList *scan = List;
    while (--n)
    {
        if (scan != NULL)
        {
            scan = scan->next;
        }
        else
        {
            fputs("error:do not have this node", stderr);
            return;
        }
    }
    scan->data = dat;
}

void LinkListDelete(LinkList *List, int n)
{
    LinkList *pre, *scan = List;
    while (--n)
    {
        if (scan != NULL)
        {
            pre = scan;
            scan = scan->next;
        }
        else
        {
            fputs("error:do not have this node", stderr);
            return;
        }
    }
    pre->next = scan->next;
    free(scan);
}

void LinkListPrint(LinkList *List)
{
    LinkList *scan = List;
    if (scan == NULL)
        fputs("error:none", stderr);
    while (scan != NULL)
    {
        printf("%d ", scan->data);
        scan = scan->next;
    }
    printf("\n");
}

void LinkListInsert(LinkList *List, int n)
{
    LinkList *scan = List;
    while (--n)
    {
        if (scan != NULL)
        {
            scan = scan->next;
        }
        else
        {
            fputs("error:do not have this node", stderr);
            return;
        }
    }
    LinkList *add = (LinkList *)malloc(sizeof(LinkList));
    printf("Please insert:");
    scanf("%d", &(add->data));
    if (scan->next == NULL)
    {
        add->next = NULL;
        scan->next = add;
    }
    else
    {
        add->next = scan->next;
        scan->next = add;
    }
}

void LinkListDestroy(LinkList *List)
{
    LinkList *scan = List, *temp;
    while (scan != NULL)
    {
        temp = scan;
        scan = scan->next;
        free(temp);
    }
    List = NULL;
}