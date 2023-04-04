#include "Link.h"

// 假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，
// 则可共享相同的后缀存储空间， 例如，“loading”和“being”的存储映像如下图所示
LinkedList SearchFirst(LinkedList L1, LinkedList L2) {
    // 获取两个链表的长度
    int len1 = getLength(L1);
    int len2 = getLength(L2);
    // 用于指向较长较短链表的第一个结点
    LinkedList longList, shortList;
    int dist;
    if (len1 > len2) {
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    }else {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while (dist -- ) longList = longList->next;
    while (longList != NULL) {
        if (longList = shortList)
            return longList;
        else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    //没有公共结点
    return NULL;
}

void printH(LinkedList L) {
    LNode *p;
    p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    LinkedList p, q;
    LinkedList L1 = Head_create_list(p);
    LinkedList L2 = Head_create_list(q);
    printL(L1);
    printf("\n");
    printL(L2);
    printf("\n");

    LinkedList res = SearchFirst(L1, L2);
    printH(res);
    printf("\n");
    return 0;
}