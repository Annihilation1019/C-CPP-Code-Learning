#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} SqStack;

/**
 * @brief 初始化栈
 * @param S 栈指针
 * @return void
 */
void Stack_Init(SqStack *S);

/**
 * @brief 判断栈是否为空
 * @param S 栈指针
 * @return bool 0/1
 */
bool Stack_isEmpty(SqStack *S);

/**
 * @brief 判断栈是否为满
 * @param S 栈指针
 * @return bool 0/1
 */
bool Stack_isFull(SqStack *S);

/**
 * @brief 入栈
 * @param S 栈指针
 * @param e 入栈元素
 * @return void
 */
void Stack_push(SqStack *S, ElemType e);

/**
 * @brief 出栈
 * @param S 栈指针
 * @param e 出栈元素
 * @return void
 */
void Stack_pop(SqStack *S, ElemType *e);

/**
 * @brief 获取栈顶元素
 * @param S 栈指针
 * @param e 栈顶元素
 * @return void
 */
void Stack_GetTop(SqStack *S, ElemType *e);

/**
 * @brief 遍历打印栈
 * @param S 栈指针
 * @return void
 */
void Stack_Print(SqStack *S);

int main()
{
    SqStack S;
    int e;
    Stack_Init(&S);     // 初始化栈
    Stack_push(&S, 2);  // 2
    Stack_push(&S, 5);  // 2 5
    Stack_Print(&S);    // 从栈顶开始读
    Stack_push(&S, 10); // 2 5 10
    Stack_push(&S, 7);  // 2 5 10 7
    Stack_push(&S, 14); // 2 5 10 7 14
    Stack_Print(&S);
    Stack_push(&S, 99); // error

    Stack_pop(&S, &e); // 2 5 10 7
    printf("%d\n", e); // 14
    Stack_pop(&S, &e); // 2 5 10
    printf("%d\n", e); // 7
    Stack_GetTop(&S, &e);
    printf("%d\n", e); // 10
    Stack_Print(&S);
    Stack_pop(&S, &e);
    Stack_pop(&S, &e);
    printf("%d\n", e); // 5
    Stack_pop(&S, &e);
    Stack_pop(&S, &e);

    return 0;
}

void Stack_Init(SqStack *S)
{
    S->top = -1; // 初始化栈顶指针，top总比元素个数小1
}

bool Stack_isEmpty(SqStack *S)
{
    if (S->top == -1)
        return true;
    else
        return false;
}

bool Stack_isFull(SqStack *S)
{
    if (S->top == MAXSIZE - 1)
        return true;
    else
        return false;
}

void Stack_push(SqStack *S, ElemType e)
{
    if (Stack_isFull(S)) // 如果栈满
    {
        fputs("The stack is full!\n", stderr);
        return;
    }
    S->data[++(S->top)] = e;
}

void Stack_pop(SqStack *S, ElemType *e)
{
    if (Stack_isEmpty(S))
    {
        fputs("The stack is empty!\n", stderr);
        return;
    }
    *e = S->data[S->top--];
}

void Stack_GetTop(SqStack *S, ElemType *e)
{
    if (Stack_isEmpty(S))
    {
        fputs("The Stack is empty!", stderr);
        return;
    }
    *e = S->data[S->top];
}

void Stack_Print(SqStack *S)
{
    int tempTop = S->top;
    while (tempTop != -1)
    {
        printf("%d ", S->data[tempTop--]);
    }
    printf("\n");
}