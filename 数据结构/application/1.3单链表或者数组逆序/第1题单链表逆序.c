#include "Link.h"

// 给定一个单链表，求出一个快速算法，实现单链表逆序
LinkedList reverseList(LinkedList head) {
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

int main()
{
    LinkedList list;
    list = Head_create_list(list);
    printL(list);
    printf("\n");
    LinkedList node = reverseList(list);
    printL(node);
    printf("\n");
}