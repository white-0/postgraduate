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

// 试写出逆转线性单链表的算法
LinkedList reverse_list(LinkedList head) {
    if (NULL == head->next) return NULL;
    LinkedList p = head->next;
    head->next = NULL;
    LinkedList tmp = NULL;
    while(p) {
        tmp = p->next;
        p->next = head->next;
        head->next = p;
        p = tmp;
    }
    return head;
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

    LinkedList L = reverse_list(L1);
    printL(L);
    return 0;
}