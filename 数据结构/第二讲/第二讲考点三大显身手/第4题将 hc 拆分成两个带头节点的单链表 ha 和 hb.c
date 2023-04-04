#include "Link.h"

/*
设有一个带头节点的单链表 hc，其节点值序列为(a1，b1，a2，b2， …，an，bn) (n≥1 , 且a、b成对出现），设计一个算法 void split( LinkList * hc, ，LinkList * &ha，LinkList * &hb)，
将 hc 拆分成两个带头节点的单链表 ha 和 hb，其中 ha 的节点值序列为 (a1，a2 ，...，an)，hb的节点值序列为(bn，bn-1，…，b1), 
要求 ha 利用原 hc 的头节点，算法的空间复杂度为O（1）。
*/
void decompose(LinkedList ha, LinkedList hb, LinkedList hc) {
    hb = (LinkedList) malloc (sizeof(LNode));
    hc = (LinkedList) malloc (sizeof(LNode));
    
    LinkedList p, q, tail;
    p = ha->next;             // 此时p指向第一个数据结点
    q = hb;
    tail = hc;
    int j = 1;

    while (p) {
        if (j % 2 != 0) {
            q->next = p;
            q = q->next;
        }else {
            tail->next = p;
            tail = tail->next;
        }
        j ++ ;
        p = p->next;
    }
    q->next = NULL;
    tail->next = NULL;

    printL(hb);
    printf("\n");
    printL(hc);
}

int main() {
    LNode p;
    LinkedList L1 = Head_create_list(&p);
    printL(L1);
    printf("\n");

    LinkedList hb, hc;
    decompose(L1, hb, hc);
}