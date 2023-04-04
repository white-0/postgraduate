#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ElemType char

typedef struct Node {
    ElemType data;
    struct Node *next;
}Node, *LinkedList;


//	给定一个单链表，判断其中是否有环？ 


int exitLoop(LinkedList head) {
    LinkedList fast, slow;
    slow = head;
    fast = head;
    while (slow != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

int main()
{
    return 0;
}