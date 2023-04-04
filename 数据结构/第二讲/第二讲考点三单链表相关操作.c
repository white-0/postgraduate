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

ElemType GetElem_L(LinkedList L, int i) {
    // L为带头结点的单链表头指针
    // 当第i个元素存在时，其赋值为e并返回OK，否则返回ERROR
    LNode *p;
    p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++ j;
    }
    if (!p || j > i) return 0;
    ElemType e = p->data;
    return e;
}

LinkedList Locate_Node(LinkedList L, int key) {
    // 在以L为头结点的单链表中查找值为key的第一个结点
    LNode *p = L->next;
    while ((p != NULL) && (p->data != key)) p = p->next;
    if (p->data == key) return p;
    else {
        printf("所查找的结点不存在！！\n");
        return NULL;
    }
}

int ListInsert_L(LinkedList L, int i, ElemType e) {
	
    // 在带头结点的单链线性表L中第i个位置之前插入元素e
    LNode *p = L;
    int j = 0;
    while (p && j < i - 1) {  // 寻找位置的过程
        p = p->next;
        ++ j;
    } // 寻找第i - 1个结点
    if (!p || j > i - 1) return 0;
    // 执行插入操作
    LNode* s;
    s = (LinkedList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

int ListDelete_L(LinkedList L, int i) {
    LNode *p;
    LNode *q;
    p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        ++ j;
    }
    if (!(p->next) || j > i - 1) return 0; // 删除位置不合理
    q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

void Delete_LinkedList(LNode *L, ElemType key) {
    LNode *p = L, *q = L->next;
    while (q != NULL && q->data != key){p = q; q = q->next;}
    if (q->data == key) {p->next = q->next; free(q);}
    else printf("所删除的结点不存在！\n");
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
    // printL(&*L2);
	
    LinkedList node = Locate_Node(&*L1, 1);
    printf("%d\n", node->data);

    ListInsert_L(&*L1, 3, 1000);

    printL(&*L1);
    printf("\n");

    ElemType e;
    e = GetElem_L(&*L1, 3);
    printf("get %d\n", e);

    ListDelete_L(&*L1, 1);

    printL(&*L1);
    printf("\n");
    return 0;
}