#include "Link.h"
/*
	用单链表保存 m 个整数，结点的结构为：[data][link]，且|data|≤n（n 为正整数）。
	现 要求设计一个时间复杂度尽可能高效的算法，对于链表中 data 的绝对值相等的结点，
	仅保留第一次出 现的结点而删除其余绝对值相等的结点。
*/
void func(LinkedList h, int n) {
    LinkedList p = h, r;
    ElemType *q, m;
    q = (ElemType *)malloc(sizeof(ElemType) * (n + 1));//申请 n+1 个位置的辅助空间
    int i;
    for (i = 0; i < n + 1; i ++ ) *(q + i) = 0; //数组元素初值置 0
    while (p->next != NULL) {
        m = p->next->data > 0 ? p->next->data : -p->next->data;
        if (*(q + m) == 0) { //判断该结点的 data 是否已出现过
            *(q + m) = 1; //首次出现
            p = p->next;  //保留
        }else { //重复出现
            r = p->next; //删除
            p->next = r->next;
            free(r);
        }
    }
    free(q);
}

int main()
{
    LinkedList list;
    list = Head_create_list(list);
    printL(list);
    printf("\n");
    func(list, 4);
    printL(list);
    printf("\n");
}