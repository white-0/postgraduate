#include "Link.h"

// 单链表快速排序
LinkedList quicksort(LinkedList head, LinkedList end){
    //如果头指针为空或者链表为空，直接返回
	if(head == NULL || head == end)   
		return NULL;
	int t;
	LinkedList p = head -> next;                  //用来遍历的指针
	LinkedList small = head;
	while( p != end){
		if( p -> data < head -> data){      //对于小于轴的元素放在左边
			small = small -> next;
			t = small -> data;
			small -> data = p -> data;
			p -> data = t;
		}
		p = p -> next;
	}
	t = head -> data;   //遍历完后，对左轴元素与small指向的元素交换
	head -> data = small -> data;
	small -> data = t;
	quicksort(head, small);                     //对左右进行递归
	quicksort(small -> next, end);
    return head;
}

int main()
{
    LinkedList list;
    list = Head_create_list(list);
    printL(list);
    printf("\n");

 
    printf("%d===\n", list->next->data);
    quicksort(list->next, NULL);
    LinkedList ss = (LinkedList)malloc(sizeof(LNode));
    ss->next = list;
    printL(ss->next);
    printf("\n");
    return 0;
}