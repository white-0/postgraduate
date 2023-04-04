#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ElemType int

typedef struct CDNode {
    ElemType data;
    struct CDNode *prior;
    struct CDNode *next;
}CDNode, *CDLinkedList;

CDLinkedList CreatCDList(CDLinkedList head, ElemType arr[], int n){
    CDLinkedList s = NULL;
    head = (CDLinkedList)malloc(sizeof(CDNode));
    head->next = NULL;
    CDLinkedList rear = head;
    int i;
    for (i = 0; i < n; i ++ ) {
        s = (CDLinkedList)malloc(sizeof(CDNode));
        s->data = arr[i];
        s->next = rear->next;
        s->prior = rear;
        rear->next = s;
        rear = s;
    }
    rear->next = head;
    head->prior = rear;
}

// 设计一个算法用于判断带头结点的循环双链表是否对称
int Symmetry(CDLinkedList L) {
    // 本算法从两头扫描循环双链表，以判断链表是否对称
    CDLinkedList p = L->next, q = L->prior;  // 两头工作指针
    while (p != q && q->next != p) {         // 循环跳出条件
        if (p->data == q->data) {            // 所指结点值相同则继续比较
            p = p->next; q = q->prior;
        }else // 否则，返回0 
            return 0;
    }
    return 1; // 比较结束返回1
}

int main() {
    ElemType arr[5] = {1, 2, 3, 2, 1};
    ElemType a[5] = {1, 2, 3, 4, 5};

    CDLinkedList h1, h2;
    h1 = CreatCDList(h1, arr, 5);
    h2 = CreatCDList(h2, a, 5);

    int i = Symmetry(h1);
    int j = Symmetry(h2);
    printf("%d\t%d\n", i, j); 
}