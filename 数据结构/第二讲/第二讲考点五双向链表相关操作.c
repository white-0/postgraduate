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


//在index位置的前面插入data结点
DLinkedList InsertListHead(DLinkedList head, int index, ElemType data) {
    DLinkedList node = (DLinkedList)malloc(sizeof(DNode));
    if (node == NULL) return NULL;
    else {
        node->data = data;
        node->prior = NULL;
        node->next = NULL;
    }
    if(index == 1) {  // 插入表头
        node->next = head;
        head->prior = node;
        head = node;
    }else {
        int i;
        DLinkedList p = head;
        for (i = 1; i < index - 1; i ++ )
            p = p->next; // 找到要插入位置前一个结点
        if (p->next == NULL) {
            p->next = node;
            node->prior = p;
        }else {
            p->next->prior = node;
            node->next = p->next;
            p->next = node;
            node->prior = p;
        }
    }
    return head;
}

// 在index位置后面插入data结点
DLinkedList InsertListEnd(DLinkedList head, int index, ElemType data) {
    DLinkedList node = (DLinkedList)malloc(sizeof(DNode));
    node->data = data;
    node->prior = NULL;
    node->next = NULL;
    int i = 1;

    DLinkedList p = head;
    while ((p->next) && (i < index + 1)) {
        p = p->next; i ++ ;
    }

    if (p->next == NULL) {
        p->next = node;
        node->prior = p;
        node->next = NULL;
    }else {
        node->next = p->prior->next;
        node->prior = p->prior;
        p->next->prior = node;
        p->prior->next = node;
    }

    return head;
}

DLinkedList DeleteList(DLinkedList head, ElemType data) {
    DLinkedList p = head;
    while (p) {
        if (p->data == data) {
            if (p->prior == NULL) { // 判断是否为头结点
                head = p->next;
                p->next = NULL;
                free(p);
                return head;
            } else if (p->next == NULL) { // 判断是否为尾结点
                p->prior->next = NULL;
                free(p);
                return head;
            } else {
                p->prior->next = p->next;
                p->next->prior = p->next;
                free(p);
                return head;
            }
        }
        p = p->next;
    }
    printf("can't find %d!\n", data);
    return head;
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

    head = InsertListHead(head, 5, 1);
    printf("insert 1 on 5 \t\t\t");
    PrintDList(head);

    head = InsertListEnd(head, 3, 7);
    printf("insert 7 on 3 \t\t\t");
    PrintDList(head);

    head = DeleteList(head, 7);
    printf("delete 7\t\t\t");
    PrintDList(head);
    return 0;
}