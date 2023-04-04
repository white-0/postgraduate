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

ElemType GetElem_C(CLinkedList L, int i) {
    // L为带头结点的单链表头指针
    // 当第i个元素存在时，其赋值为e并返回OK，否则返回ERROR
    CNode *p;
    p = L->next;
    int j = 1;
    while (p != L && j < i) {
        p = p->next;
        ++ j;
    }
    if (p == L || j > i) return 0;
    ElemType e = p->data;
    return e;
}

CLinkedList Locate_Node(CLinkedList L, ElemType key) {
    // 在以L为头结点的单链表中查找值为key的第一个结点
    int j = 1;
    CNode *p = L->next;
    while ((p != L) && (p->data != key)) {
        p = p->next; j ++ ;
    }
    if(p->data == key) {
        printf("%d is located on %d \n", p->data, j);
        return p;
    }else {
        printf("所查找的结点不存在！！\n");
        return NULL;
    }
}

int ListInsert_C(CLinkedList L, int i, ElemType e) {
    int j = 0;
    CLinkedList node = L, s;
    while (node->next != L && j < i - 1) {
        j ++ ; node = node->next;
    }
    if (node == L || j > i - 1 && i != 1){
        printf("插入失败!\n"); return 0;
    }else {
        s->data = e;
        s->next = node->next;
        node->next = s;
    }
    return 1;
}

int ListDelete_C(CLinkedList L, int i) {
    int j = 0;
    CLinkedList node = L, s;
    while (node->next != L && j < i - 1) {
        j ++ ; node = node->next;
    }
    if ((node->next != L || j < i - 1) && (j != i - 1)) {
        printf("删除失败！");
        return 0;
    }else {
        s = node->next;
        node->next = s->next;
        free(s);
    }
    return 1;
}

void printC(CLinkedList L) {
    CNode *p;
    p = L->next;
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    CNode p, q;
    CLinkedList L1 = Head_create_Clist(&p);
    CLinkedList L2 = Tail_create_Clist(&p);
    printC(&*L1);
    printf("\n");
    printC(&*L2);
    printf("\n");

    CLinkedList node = Locate_Node(&*L1, 4);
    printf("%d\n", node->data);

    ListInsert_C(&*L1, 8, 1000);

    printC(&*L1);
    printf("\n");

    ElemType e;
    e = GetElem_C(&*L1, 3);
    printf("get %d\n", e);

    ListDelete_C(&*L1, 5);

    printC(&*L1);
    return 0;
}