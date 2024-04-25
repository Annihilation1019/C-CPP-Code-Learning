#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 6
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int front, rear;
} SqQueue;

/**
 * @brief 队列初始化
 * @param Q 队列指针
 * @return void
 */
void Queue_Init(SqQueue *Q);

/**
 * @brief 判断队列是否为空
 * @param Q 队列指针
 * @return bool 0/1
 */
bool Queue_isEmpty(SqQueue *Q);

/**
 * @brief 判断队列是否为满
 * @param Q 队列指针
 * @return bool 0/1
 */
bool Queue_isFull(SqQueue *Q);

/**
 * @brief 返回队列长度
 * @param Q 队列指针
 * @return int 队列长度
 */
int Queue_Len(SqQueue *Q);

/**
 * @brief 入队
 * @param Q 队列指针
 * @param e 入队元素
 * @return void
 */
void Queue_Enter(SqQueue *Q, ElemType e);

/**
 * @brief 出队
 * @param Q 队列指针
 * @param e 出队元素
 * @return void
 */
void Queue_Remove(SqQueue *Q, ElemType *e);

/**
 * @brief 打印队列
 * @param Q 队列指针
 * @return void
 */
void Queue_Print(SqQueue *Q);

int main()
{
    SqQueue Q;
    ElemType e;

    Queue_Init(&Q);
    for (ElemType i = 1; i <= 5; i++)
    {
        Queue_Enter(&Q, i); // 1 2 3 4 5
    }
    Queue_Print(&Q);
    Queue_Remove(&Q, &e);
    Queue_Remove(&Q, &e);
    Queue_Enter(&Q, 7);
    Queue_Print(&Q); // 3 4 5 7
    printf("%d\n", Queue_Len(&Q));
    Queue_Enter(&Q, 5);
    Queue_Print(&Q);
    Queue_Enter(&Q, 8);

    Queue_Init(&Q);
    printf("%d\n", Queue_Len(&Q));
    Queue_Print(&Q);

    return 0;
}

void Queue_Init(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

bool Queue_isEmpty(SqQueue *Q)
{
    return Q->front == Q->rear;
}

bool Queue_isFull(SqQueue *Q)
{
    return (Q->rear + 1) % MAXSIZE == Q->front;
}

int Queue_Len(SqQueue *Q)
{
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

void Queue_Enter(SqQueue *Q, ElemType e)
{
    if (Queue_isFull(Q))
    {
        fputs("The Queue is full!\n", stderr);
        return;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}

void Queue_Remove(SqQueue *Q, ElemType *e)
{
    if (Queue_isEmpty(Q))
    {
        fputs("The Queue is full!\n", stderr);
        return;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
}

void Queue_Print(SqQueue *Q)
{
    int tem_front = Q->front;
    int tem_rear = Q->rear;
    if (Queue_isEmpty(Q))
    {
        fputs("The Queue is empty!\n", stderr);
    }
    while (tem_front != tem_rear)
    {
        printf("%d ", Q->data[tem_front]);
        tem_front = (tem_front + 1) % MAXSIZE;
    }
    printf("\n");
}