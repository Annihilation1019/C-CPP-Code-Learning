#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType *data;
    int len; // 线性表长度
} LineList;

/**
 * @brief 初始化线性表
 * @param List 线性表
 * @param len 创建线性表长度
 * @return 状态码
 */
Status LineListInit(LineList *List, int len);

/**
 * @brief 判断线性表是否已满
 * @param List 线性表指针
 * @return 是否已满
 */
bool LineList_isFull(LineList *List);

/**
 * @brief 判断线性表是否为空
 * @param List 线性表指针
 * @return 是否为空
 */
bool LineList_isEmpty(LineList *List);

/**
 * @brief 插入元素
 * @param List 线性表指针
 * @param location 插入位置，0开始
 * @param e 插入元素
 * @return 状态码
 */
Status LineListInsert(LineList *List, int location, ElemType e);

/**
 * @brief 删除元素
 * @param List 线性表指针
 * @param location 删除位置，0开始
 * @param e 获取删除元素
 * @return 状态码
 */
Status LineListDelete(LineList *List, int location, ElemType *e);

/**
 * @brief 获取元素
 * @param List 线性表指针
 * @param location 获取位置，0开始
 * @param e 获取元素
 * @return 状态码
 */
Status LineListGetElem(LineList *List, int location, ElemType *e);

/**
 * @brief 打印线性表
 * @param List 线性表指针
 * @return 状态码
 */
Status LineListPrint(LineList *List);

/**
 * @brief 销毁线性表
 * @param List 线性表指针
 * @return void
 */
void LineListDestroy(LineList *List);

int maxsize;

int main()
{
    LineList List;
    maxsize = 10;
    LineListInit(&List, maxsize); // 初始化线性表
    for (int i = 0; i < maxsize; i++)
    {
        LineListInsert(&List, i, i); // 插入元素
    }
    LineListPrint(&List); // 打印线性表
    ElemType e;
    LineListDelete(&List, 5, &e);  // 删除元素
    LineListPrint(&List);          // 打印线性表
    LineListGetElem(&List, 5, &e); // 获取元素
    printf("%d", e);
    LineListDestroy(&List); // 销毁线性表
    return 0;
}

Status LineListInit(LineList *List, int len)
{
    List->data = (ElemType *)malloc(len * sizeof(ElemType));
    if (List->data == NULL)
    {
        fputs("fail to allocate memory!\n", stderr);
        return ERROR;
    }
    List->len = 0;
    return OK;
}

bool LineList_isFull(LineList *List)
{
    return List->len == maxsize ? true : false;
}

bool LineList_isEmpty(LineList *List)
{
    return List->len == 0 ? true : false;
}

Status LineListInsert(LineList *List, int location, ElemType e)
{
    if (LineList_isFull(List))
    {
        fputs("error:The list is full!\n", stderr);
        return ERROR;
    }
    if (location < 0 || location > List->len)
    {
        fputs("error:The list do not have this location\n", stderr);
        return ERROR;
    }

    if (location < List->len)
    {
        for (int i = List->len - 1; i >= location; i--)
        {
            List->data[i + 1] = List->data[i];
        }
    }
    List->data[location] = e;
    List->len++;
    return OK;
}

Status LineListDelete(LineList *List, int location, ElemType *e)
{
    if (LineList_isEmpty(List))
    {
        fputs("error:The list is empty!\n", stderr);
        return ERROR;
    }
    if (location < 0 || location >= List->len)
    {
        fputs("error:The list do not have this location\n", stderr);
        return ERROR;
    }

    *e = List->data[location];
    if (location < List->len)
    {
        for (int i = location; i < List->len; i++)
        {
            List->data[i] = List->data[i + 1];
        }
    }
    List->len--;
    return OK;
}

Status LineListGetElem(LineList *List, int location, ElemType *e)
{
    if (LineList_isEmpty(List) || location < 0 || location >= List->len)
    {
        fputs("error:can't get this element!\n", stderr);
        return ERROR;
    }
    if (location < 0 || location >= List->len)
    {
        fputs("error:The list do not have this location\n", stderr);
        return ERROR;
    }
    *e = List->data[location];
    return OK;
}

Status LineListPrint(LineList *List)
{
    if (LineList_isEmpty(List))
    {
        fputs("error:The list is empty!\n", stderr);
        return ERROR;
    }
    for (int i = 0; i < List->len; i++)
    {
        printf("%d ", List->data[i]);
    }
    return OK;
}

void LineListDestroy(LineList *List)
{
    free(List->data);
    List->data = NULL;
}