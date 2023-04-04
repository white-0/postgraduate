#include "Link.h"
/*
	给定两个单链表(为简化，假设两个链表均不含有环)的头指针分别为headl和 head2，
	请设计一个算法判断这两个单链表是否相交，如果相交则返回第一个交点，
	要求算法的时间复杂度为O( lengthl + length2)，
	其中 length1和 length2分别为两个单链表的长度。
*/
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