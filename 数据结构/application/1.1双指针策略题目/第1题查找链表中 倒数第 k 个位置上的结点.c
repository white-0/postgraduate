#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *link;
}LNode, *LinkedList;

LinkedList Head_create_list(LinkedList head) {
    head = (LinkedList)malloc(sizeof(LNode));   // 为头指针开辟内存空间
    LNode *node = NULL;                         // 定义工作指针
    int count = 0;                              // 创建结点的指针
    head->link = NULL;                          
    node = head->link;                          // 将最后一个结点的指针域永远保持为NULL
    scanf("%d", &count);
    int i;
    for (i = 0; i < count; i ++ ) {
        node = (LNode *)malloc(sizeof(LNode));  // 为新结点开辟内存空间
        node->data = i;                         // 为新结点的数据赋值
        // 将头指针所指向的下一个结点的地址，赋给新创建结点的next
        node->link = head->link;
        // 将新创建的结点的地址赋给头指针下一个结点
        head->link = node;
    }
    return head;
}

// 假设该链表只给出了头指针 list。在不改变链表的前提下，
// 请设计一个尽可能高效的算法，查找链表中 倒数第 k 个位置上的结点( k 为正整数)。
// 若查找成功，算法输出该结点的 data 域的值，并返回 1；否则，只 返回 0。
int Search_K(LinkedList list, int k) {
    LinkedList p = list->link, q = list->link; // 指针p、q指示第一个结点
    int count = 0;
    while (p != NULL) { // 遍历链表直到最后一个结点
        if (count < k){
            count ++ ;
            p = p->link;
        }else {
            q = q->link;
            p = p->link;
        }
    }
    if (count < k) return 0;
    else {
        printf("%d", q->data);
        return 1;
    }
}

void printL(LinkedList L) {
    LNode *p;
    p = L->link;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->link;
    }
}

int main()
{
    LinkedList list;
    list = Head_create_list(list);
    Search_K(list, 9);
    printf("\n");
    printL(list);
    printf("\n");
    return 0;
}