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

LinkedList Tail2_create_list(LinkedList head) {
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

LinkedList Merge_LinkedList(LinkedList La, LinkedList Lb) {
    // 合并以La, Lb为头结点的两个有序单链表
    LNode *Lc, *pa, *pb, *pc, *ptr;
    Lc = La; pc = La; pa = La->next; pb = Lb->next;
    while (pa != NULL && pb != NULL)
    {
        // 将pa所指的结点合并，pa指向下一个结点
        if (pa->data < pb->data) {pc->next = pa; pc = pa; pa = pa->next;}
        // 将pb所指的结点合并，pb指向下一个结点
        // else (pa->data > pb->data) {pc->next = pb; pc = pb; pb = pb->next;}
        else {pc->next = pb; pc = pb; pb = pb->next;}
        // else {
        //     pc->next = pa; pc = pa; pa = pa->next; ptr = pb; pb = pb->next; free(ptr);
        // }
        // 将pa所指的结点合并，pb所指的结点删除
    }
    if (pa != NULL) pc->next = pa;
    if (pb != NULL) pc->next = pb;
    free(Lb);
    return (Lc);
}


// 删除单链表中所有值重复的结点，使得所有结点的值都不相同。

void Delete_Node_Value(LinkedList L) {
    // 删除以L为结点的单链表中所有值相同的结点
    LNode *p = L->next, *q, *ptr;
    while (p != NULL) { // 检查链表中的所有结点
        q = p, ptr = p->next;
        //检查结点p的所有后继结点ptr
        while (ptr != NULL) {
            if (ptr->data == p->data) {p->next = ptr->next; free(ptr); ptr = q->next;}
            else {q = ptr = ptr = ptr->next;}
        }
        p = p->next;
    }
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
    LNode p, q;
    LinkedList L1 = Tail_create_list(&p);
    printL(L1);
    printf("\n");

    LinkedList L2 = Tail2_create_list(&q);
    printL(L2);
    printf("\n");

    LinkedList L = Merge_LinkedList(L1, L2);
    printL(L);
    printf("\n");

    Delete_Node_Value(L);
    printL(L);
    return 0;
}