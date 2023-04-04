#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ElemType int 

typedef struct LNode {
    ElemType data;       // 存放元素值
    struct LNode *next;  // 指向后继结点
}LNode, *LinkedList;     // 单链表结点类型

LinkedList Head_create_list(LinkedList head) {
    head = (LinkedList)malloc(sizeof(LNode));   // 为头指针开辟内存空间
    LNode *node = NULL;                         // 定义工作指针
    int count = 0;                              // 创建结点的指针
    head->next = NULL;                          
    node = head->next;                          // 将最后一个结点的指针域永远保持为NULL
    scanf("%d", &count);
    int i;
    for (i = 0; i < count; i ++ ) {
        node = (LNode *)malloc(sizeof(LNode));  // 为新结点开辟内存空间
        node->data = i;                         // 为新结点的数据赋值
        // 将头指针所指向的下一个结点的地址，赋给新创建结点的next
        node->next = head->next;
        // 将新创建的结点的地址赋给头指针下一个结点
        head->next = node;
    }
    return head;
}

// LinkedList minMoveFirst(LinkedList head) {
//     head = head->next; //若链表没有头结点，这一步就删掉
//     LinkedList minNode;                      // 最小结点
//     LinkedList previousMinNode;              // 最小结点的前驱结点
//     LinkedList previous;                     // 前驱结点
//     LinkedList current;                      // 当前结点
//     if (NULL == head) { return head; }       // 空链表直接返回
//     minNode = previous = head;         
//     current = head->next;              
//     while (NULL != current) { 
//         if (current->data < minNode->data) { // 结点数据比较
//             previousMinNode = minNode;       // 移动，最小结点变为最小结点的前驱结点
//             minNode = current;               // 当前结点为最小结点
//         }
//         previous = current;                  // 记录前驱结点
//         current = current->next;             // 当前结点后移
//     }
//     // 此时的previous指向表尾
//     if (minNode == head)                     // 最小结点是首结点
//         head = head->next;                   // 首结点后移
//     else 
//         previousMinNode->next = minNode->next;
//     minNode->next = head;
//     head = minNode;
//     return head;
// }

/*
	已知非空线性链表由list 指出，链结点的构造为( data，link)。
	请写一算法，将链表中数据域值最小的那个链结点移到链表的最前面。
	要求:不得额外申请新的链结点。
*/

void minMoveFirst(LinkedList head) {
    LinkedList min;                          // 最小结点
    LinkedList premin;                       // 最小结点的前驱结点
    LinkedList pre;                          // 前驱结点
    LinkedList cur;                          // 当前结点
    if (NULL == head) { return; }       // 空链表直接返回
    pre = head; cur = head->next;
    premin = pre; min = cur;
    while (cur) {
        if (min->data > cur->data) {         // 结点数据比较
            premin = pre;                    // 移动，最小结点变为最小结点的前驱结点
            min = cur;                       // 当前结点为最小结点
        }
        pre = cur;                           // 记录前驱结点
        cur = cur->next;                     // 当前结点后移
    }
    premin->next = min->next;
    min->next = head->next;
    head->next = min;
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
    LinkedList L1 = Head_create_list(&p);
    // LinkedList L2 = Tail_create_list(&p);
    printL(&*L1);
    printf("\n");

    minMoveFirst(L1);
    printL(L1);

    return 0;
}