#include "Link.h"


// 请设计一个空间复杂度为O(1)且时间上尽可能高效的算法，重新排列L 中的各结点，
// 得到线性表 L'=(a1，an，a2，an-1，an-2，…)。

// 翻转链表
LinkedList reverse(LinkedList head) {
    LinkedList tmp = NULL;
    LinkedList cur = NULL;
    LinkedList node = NULL;
    if (head == NULL) return NULL;
    node = head;
    cur = head->next;
    while (cur != NULL)
    {
        tmp = cur->next;
        cur->next = node;
        node = cur;
        cur = tmp;
    }
    head->next = NULL;
    return node;
}

// 找到中点
LinkedList findMidPoint(LinkedList head) {
    LinkedList fast = head;
    LinkedList slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void change_list(LinkedList h) {
    LinkedList midP = findMidPoint(h);
    LinkedList half = (LinkedList)malloc(sizeof(LNode));
    half->next = midP;
    half = reverse(midP);
    LinkedList p, q;
    p = h->next; q = half->next;
    LinkedList tmp1 = h;
    LinkedList tmp2 = h;
    while (p != NULL && q != NULL) {
        tmp1 = p->next;
        p->next = q;
        tmp2 = q->next;
        q->next = tmp1;
        p = tmp1;
        q = tmp2;
    }
    
}

int main()
{
    LinkedList list;
    list = Head_create_list(list);
    printL(list);
    printf("\n");
    change_list(list);
    printL(list);
    printf("\n");

}