#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define ElemType int 

typedef struct DNode
{
    ElemType data;          // 数据域
    struct DNode *prior;    // 向前的指针
    struct DNode *next;     // 向后的指针
}DNode, *DLinkedList;

// 新建数据域为data的结点
DLinkedList CreateNode(DLinkedList node) {
    node = (DLinkedList)malloc(sizeof(DNode));
    if(node == NULL) return NULL;
    
    node->prior = NULL;
    node->next = NULL;
    node->data = rand() % 100;

    return node;
}

DLinkedList CreateList(DLinkedList head, int len) {
    if (len == 1) return CreateNode(head);
    else {
        int i;
        head = CreateNode(head);
        DLinkedList list = head;
        for (i = 1; i < len; i ++ ) {
            DLinkedList p = (DLinkedList)malloc(sizeof(DNode));
            p->prior = NULL;
            p->next = NULL;
            p->data = rand() % 100;
            
            list->next = p;
            p->prior = list;
            list = list->next;
        }
    }
    return head;
}

/*
	设有一个循环双链表，其中有一结点的指针为p, 
	编写一个函数，实现p 与其右边的一个结点进行交换。
*/
DLinkedList swap(DLinkedList D, int m) {
    DLinkedList p = D;
    while (m -- ) p = p->next;
    if (p == NULL) return NULL;
    else {
        DLinkedList q = p->next;
        p->next = q->next;
        p->next->prior = p;
        p->prior->next = q;
        q->prior = p->prior;
        p->prior = q;
        q->next = p;
    }
    return D;
}

void PrintDList(DLinkedList head) {
    DLinkedList p = head;
    while (p) {
        if (p->next == NULL) printf("%d\n", p->data);
        else printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    DLinkedList head = NULL;
    head = CreateList(head, 5);
    printf("new double list is \t");
    PrintDList(head);

    head = swap(head, 2);
    PrintDList(head);
    
    return 0;
}