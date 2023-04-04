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
    for (i = 0; i < count / 2; i ++ )
    {
        node = (LNode *)malloc(sizeof(LNode));   // 为新结点开辟新内存
        node->data = i;                          // 新结点的数据域赋值
        end->next = node;                        // 新结点赋给end的下一个
        end = node;                              // 新结点成为新的尾结点

        node = (LNode *)malloc(sizeof(LNode));   // 为新结点开辟新内存
        node->data = i;                          // 新结点的数据域赋值
        end->next = node;                        // 新结点赋给end的下一个
        end = node;                              // 新结点成为新的尾结点
    }
    end->next = NULL;
    return head;
}

/*
已知带头结点的单链表有data和 next 两个域，设计一个算法，将该链表中的重复元素结点删除，
例如:(7，10，10，21，30，42，42，42，51，70)将变作(7，10，21，30，42，51，70)。
*/

LinkedList DeleteList(LinkedList La) { // 删除带头结点的单链la中所有重复元
    LinkedList pre = La->next;
    while (pre != NULL) {
        ElemType m = pre->data;
        LinkedList q = pre;
        LinkedList p = pre->next;
        while (p != NULL) {
            if (p->data == m) {       // 删除重复结点
                LinkedList u = p;
                p = p->next;
                free(u);
            }else {                   // 不重复就继续向后遍历 
                q->next = p;
                q = p;
                p = p->next;
            }
        }
        q->next = p;                  // 判断下一个元素的所有相同元素
        pre = pre->next;
    }
    return La;
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

    LinkedList L2 = DeleteList(L1);
    printL(L2);

    return 0;
}