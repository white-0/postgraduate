#include "Link.h"

/*给定一个链表，进行旋转链表的操作，讲链表每个结点向右移动k个位置，其中k是非负数*/
LinkedList rotateRight1(LinkedList head, int k) {
    if (!head) return NULL;
    int n = 0;
    LinkedList cur = head;
    while (cur) {
        ++n;
        cur = cur->next;
    }
    k %= n;
    LinkedList fast = head, slow = head;
    for (int i = 0; i < k; ++i) {
        if (fast)  fast = fast->next;
    }
    if (!fast) return head;
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = head;
    fast = slow->next;
    slow->next = NULL;
    return fast;
}

LinkedList rotateRight(LinkedList head, int k) {
        if (!head) return NULL;
        int n = 1;
        LinkedList cur = head;
        while (cur->next) {
            ++n;
            cur = cur->next;
        }
        cur->next = head;
        int m = n - k % n;
        for (int i = 0; i < m; ++i) {
            cur = cur->next;
        }
        LinkedList newhead = cur->next;
        cur->next = NULL;
        return newhead;
}

int main()
{
    LinkedList list1, list2;
    
    list1 = Head_create_list(list1);
    list2 = Tail_create_list(list2);

    list1 = list1->next;
    list2 = list2->next;

    printL(list1);printf("\n");
    printL(list2);printf("\n");

    list1 = rotateRight1(list1, 4);
    list2 = rotateRight(list2, 2);

    printL(list1);printf("\n");
    printL(list2);printf("\n");
}