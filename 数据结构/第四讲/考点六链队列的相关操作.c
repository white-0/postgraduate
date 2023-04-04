#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define Elemtype int

typedef struct QNode
{
    Elemtype data;
    struct QNode *next;
}QNode;

typedef struct link_queue
{
    QNode *front, *rear;
}LinkQueue;

LinkQueue * Init_LinkedQueue() {
    LinkQueue *Q; QNode *p;
    p = (QNode *)malloc(sizeof(QNode)); // 开辟头结点
    p->next = NULL;
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    // 开辟链表的指针结点
    Q->front = Q->rear = p;
    return Q;
}

void Destory_LinkedQueue(LinkQueue *Q) {
    while (Q->front != NULL) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front->next;
    }
}

int Insert_LinkedQueue(LinkQueue *Q, Elemtype e) {
     QNode *p = (QNode *)malloc(sizeof(QNode));
     if (!p) return 0;
     p->data = e; p->next = NULL;
     Q->rear->next = p; Q->rear = p;
     return 1;
}

int Delete_LinkedQueue(LinkQueue *Q, Elemtype *x) {
    QNode *p;
    if (Q->front == Q->rear) return 0;
    p = Q->front->next;
    *x = p->data;
    Q->front->next = p->next;
    if (p == Q->rear) Q->rear = Q->front;
    free(p);
    return 1;
}

int main()
{
    LinkQueue* qq = Init_LinkedQueue();
    Insert_LinkedQueue(qq, 12);
    Insert_LinkedQueue(qq, 33);
    Elemtype x, y;
    Delete_LinkedQueue(qq, &x);
    Delete_LinkedQueue(qq, &y);
    printf("%d %d",x, y);
    return 0;
}