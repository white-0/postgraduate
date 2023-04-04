#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ElemType int 

typedef struct CNode {
    ElemType data;       // 存放元素值
    struct CNode *next;  // 指向后继结点
}CNode, *CLinkedList;    // 循环单链表结点类型

void init(CLinkedList head) {
    if (head == NULL) return ;
    head->next = head;
}

CLinkedList Head_create_Clist(CLinkedList head) {
    head = (CLinkedList)malloc(sizeof(CNode));
    head->next = head;
    CLinkedList node;
    int i, count;
    scanf("%d", &count);
    for (i = 0; i < count; i ++ ) {
        node = (CLinkedList)malloc(sizeof(CNode));
        node->data = i;
        node->next = head->next;
        head->next = node;
    }
    return head;
}

CLinkedList Tail_create_Clist(CLinkedList head) {
    head = (CLinkedList)malloc(sizeof(CNode));
    CLinkedList pre = head, node;
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i ++ ) {
        node = (CLinkedList)malloc(sizeof(CNode));
        node->data = i;
        node->next = head;
        pre->next = node;
        pre = node;
    }
    return head;
}

int CListIsEmpty(CLinkedList L) {
    return L->next == L ? 0 : 1;
}

int getCLength(CLinkedList L) {
    int len = 0;
    CLinkedList node = L->next;
    while (node != L) {
        len ++ ; node = node->next;
    }
    return len;
}

/*
	设有一个带头结点的循环单链表,其结点值均为正整数设计一个算法、
	反复找出单链表中结点值最小的结点并输出，
	然后将该结点从中删除直到单链表空为止，再删除表头结点
*/

void del_min(CLinkedList L) {
    while (L->next != L) {
        CLinkedList p = L->next;
        CLinkedList pre = L;
        int min = p->data;

        while (p->next != L) {
            if (p->next->data <= min) {
                min = p->next->data;
                pre = p;
            }
            p = p->next;
        }
        printf ("%d ", min);
        CLinkedList temp = pre->next;
        pre->next = pre->next->next;
        free(temp); 
    }
    printf("\n");
    free(L);
}

void printC(CLinkedList L) {
    CLinkedList p;
    p = L->next;
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    CLinkedList p, q;
    CLinkedList L1 = Head_create_Clist(p);

    // printC(&*L1);
    del_min(L1);
    printf("\n");
    return 0;
}