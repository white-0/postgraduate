#include "Link.h"

/*
	给定一个链表和一个特定值 x，对链表进行分隔，
	使得所有小于 x 的节点都在大于或等于 x 的节点之前。
	应当保留两个分区中每个节点的初始相对位置。
*/

LinkedList partition(LinkedList head, int x) {
        LinkedList dummy = (LinkedList)malloc(sizeof(LNode));
        dummy->next = head;
        LinkedList pre = dummy, cur = head;;
        while (pre->next && pre->next->data < x)  pre = pre->next;
        cur = pre;
        while (cur->next) {
            if (cur->next->data < x) {
                LinkedList tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
int main()
{
    LinkedList head;
    head = Tail_create_list(head);
    printL(head);
    printf("\n");   
    head = partition(head, 3);
    printL(head);
    printf("\n");  
}