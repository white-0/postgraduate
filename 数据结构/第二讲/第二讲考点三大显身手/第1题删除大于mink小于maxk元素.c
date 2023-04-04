#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ElemType int

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkedList;

LinkedList Tail_create_list(LinkedList head) {
    head = (LinkedList)malloc(sizeof(LNode));    // 为头结点开辟内存空间
    LinkedList node = NULL;                      // 定义工作指针
    LinkedList end = NULL;                       // 定义为指针
    head->next = NULL;                           // 初始化头结点指向的下一个地址为NULL
    end = head;                                  // 未创建其余结点之前，只有一个头结点
    int count = 0;                               // 结点个数
    scanf("%d", &count);
    int i;
    for (i = 0; i < count; i ++ )
    {
        node = (LNode *)malloc(sizeof(LNode));   // 为新结点开辟新内存
        node->data = i;                          // 新结点的数据域赋值
        end->next = node;                        // 新结点赋给end的下一个
        end = node;                              // 新结点成为新的尾结点
    }
    end->next = NULL;
    return head;
}
// 已知线性表中的元素以值递增有序排列，并以单链表作存储结构。试设计一个高效的算法，
// 删除表中所有值大于mink 且小于maxk 的元素（若表中存在这样的元素），同时释放被删结点空间
// （注意： mink 和maxk 是给定的两个参变量。它们的值可以和表中的元素相同，也可以不同）。
int DeleteMiddleElem(LinkedList L, int mink, int maxk) {
    // 删除单链表中大于mink到小于maxk之间的数据元素
    LinkedList p, q, prev = NULL;
    if (mink > maxk) return -1;   // mink,maxk 大小不合法
    p = L;
    prev = p;                     // prev 指向头结点
    p = p->next;                  // 为了保证prev指向p的直接前驱结点
    // 只需要遍历从首元结点到data域为maxk结点的数据元素
    while (p && p->data < maxk) {
        if (p->data <= mink) {
            prev = p;             // prev指向第一个data域大于等于mink的结点
            p = p->next;
        } else {                  // data域大于mink
            prev->next = p->next; // prev（指向 mink）指向p的直接后继结点
            q = p;
            p = p->next;
            free(q);              // 释放内存空间
        }
    }
    return 1;
}

void printL(LinkedList L) {
    LNode *p;
    p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    LNode p;
    LinkedList L1 = Tail_create_list(&p);
    printL(L1);
    printf("\n");

    DeleteMiddleElem(L1, 7, 10);
    printL(L1);

    return 0;
}