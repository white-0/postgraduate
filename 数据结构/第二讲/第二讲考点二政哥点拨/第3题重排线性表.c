#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ElemType int
#define MAX_SIZE 100

typedef struct {
    ElemType* elem;     // 存储空间基址
    int length;         // 当前长度
}SqList;

void InitList(SqList *L)
{
	L->elem = (ElemType *)malloc(MAX_SIZE * sizeof(ElemType));
	if(!L->elem)
	{
		printf("存储空间分配失败!");
	}
	L->length = 0;
}

int ListInsert(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return 0;
    if (L->length >= MAX_SIZE) return 0;

    int j;
    for (j = L->length; j >= i; j -- )
        L->elem[j] = L->elem[j - 1];
    L->elem[i - 1] = e;
    L->length ++ ;
    return 1;
}

// 一个线性表中的元素为全部为正或者负整数，
// 试设计一算法，在尽可能少的时间内重排该表，
// 将正、负整数分开，使线性表中所有负整数在正整数前面。
void ReArrange(SqList* a, int n) {
    int low = 0, high = n - 1;
	ElemType t = a->elem[low]; // 枢纽元素，只是暂存，不作为比较对象
    while (low < high) {
        while (low < high && a->elem[high] >= 0) high -- ;  // 寻找小于0的元素
        a->elem[low] = a->elem[high];
		while (low < high && a->elem[low] < 0) low ++ ;     // 寻找大于0的元素
        a->elem[high] = a->elem[low];
    }
	a->elem[low] = t; // 将枢纽元素放到最终位置
}

void ListPrint(SqList* L) {
    int i;
    for (i = 0; i < L->length; i ++ )
        printf ("%d %d\n", i, L->elem[i]);
    printf("\n");
}

int main()
{
    SqList L1;
    InitList(&L1);

    ListInsert(&L1, 1, -1);
    ListInsert(&L1, 2, -5);
    ListInsert(&L1, 3, 2);
    ListInsert(&L1, 4, -8);
	ListInsert(&L1, 5, -5);
    ListInsert(&L1, 6, 23);
	ListInsert(&L1, 7, -10);
    ListInsert(&L1, 8, -8);
	ListInsert(&L1, 9, -4);
    ListInsert(&L1, 10, 8);

    ListPrint(&L1);
    
    ReArrange(&L1, L1.length);

    ListPrint(&L1);
    return 0;
}