/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-25 18:51:50
 * @LastEditTime: 2021-07-25 20:52:44
 * @LastEditors: Mr. Lee
 */

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int head;
    int tail;
    int data[100];
};

struct stack
{
    int top;
    int data[10];
};

int main()
{
    int i, t;
    struct queue *q1, *q2;
    struct stack *s;
    int book[100];
    q1->head = 1;
    q1->tail = 1;
    q2->head = 1;
    q2->tail = 1;

    s->top = 0;
    for (i = 0; i < 10; i++)
    {
        book[i] = 0;
    }

    for (i = 0; i < 7; i++)
    {
        scanf("%d", &q1->data[q1->tail]);
        q1->tail++;
    }

    for (i = 0; i < 7; i++)
    {
        scanf("%d", &q1->data[q2->tail]);
        q2->tail++;
    }

    while (q1->head < q1->tail && q2->head < q2->tail)
    {
        t = q1->data[q1->head];
        if (book[t] == 0)
        {
            q1->head++;
            s->top++;
            s->data[s->top] = t;
            book[t] = 1;
        }
        else
        {
            q1->head++;
            q1->data[q1->tail] = s->data[s->top];
            q1->tail++;
            s->top--;
        }

        t = q2->data[q2->head];
        if (book[t] == 0)
        {
            q2->head++;
            s->top++;
            s->data[s->top] = t;
            book[t] = 1;
        }
        else
        {
            q2->head++;
            q2->data[q2->tail] = t;
            q2->tail++;
            while (s->data[s->top] != t)
            {
                q2->data[q2->tail] = s->data[s->top];
                book[s->data[s->top]] = 0;
                q2->tail++;
                s->top--;
            }
        }
    }

    if (q2->head == q2->tail)
    {
        printf("q1 YES\n");
        for (i = q1->head; i < q1->tail; i++)
        {
            printf("%d ", q1->data[i]);
        }
    }
    else
    {
        printf("q2 YES\n");
        for (i = q2->head; i < q2->tail; i++)
        {
            printf("%d ", q2->data[i]);
        }
    }

    return 0;
}
