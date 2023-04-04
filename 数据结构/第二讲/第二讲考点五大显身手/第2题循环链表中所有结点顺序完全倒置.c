#include "Link.h"

/*
	已知L为链表的头结点地址，表中共有m(m>3)个结点，
	从表中第i个结点(1<i<m)到第m个结点构成一个循环部分链表，
	设计将这部分循环链表中所有结点顺序完全倒置的算法。
*/

void geta(LinkedList s, int i, int m ) {
	int count = 1;
	LinkedList r, p, pre, w;
	p = s->next;
	while (count < m && p != NULL) {
		if (count == i) r = p;
		count ++ ;
		p = p->next;
	}
	if (p == NULL) return;
	else p->next = r;

	count = 1;
	pre = s;
	p = pre->next;

	while (count < i) {
		pre = p;
		p = p->next;
		count ++ ;
	}
	r = pre;
	pre = p;
	p = p->next;

	while (p != pre) {
		pre->next = p->next;
		p->next = r->next;
		r->next = p;
		p = pre->next;
	}
	pre->next = r->next;
	w = s->next;
	while (w!=NULL) {
		w->data = w->data + 1;
		if(w->data >= 2) break;
		w = w->next;
	}
}
int main()
{
    LinkedList head;
    head = Head_create_list(head);
    printL(head);
    printf("\n");

    geta(head, 2, 5);
    printL(head);
    printf("\n");
    return 0;
}