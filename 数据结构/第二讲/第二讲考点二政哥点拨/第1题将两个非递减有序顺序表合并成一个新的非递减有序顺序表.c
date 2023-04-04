#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ElemType int
#define MAX_SIZE 100 

typedef struct {
    ElemType* elem;     // 存储空间基址
    int length;         // 当前长度
    int listsize;       // 当前分配的存储容量
}SqList;

void InitList(SqList *L)
{
	L->elem = (ElemType *)malloc(MAX_SIZE * sizeof(ElemType));
	if(!L->elem)
	{
		printf("存储空间分配失败!");
	}
	L->length = 0;
    L->listsize = 100;
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

void ListPrint(SqList* L) {
    int i;
    for (i = 0; i < L->length; i ++ )
        printf ("%d %d\n", i, L->elem[i]);
    printf("\n");
}

// 编写算法，将两个非递减有序顺序表A和B合并成一个新的非递减有序顺序表c,
// 已知顺序表A 和B 的元素个数分别为m 和n

// 方法一
void Combination(SqList* L1, SqList* L2, SqList* L3) {
    if (L1->length + L2->length > L3->listsize) return;
    int i = 0, j = 0, k = 0;
    while ((i != L1->length) && (j != L2->length)) {
        if (L1->elem[i] > L2->elem[j]) { // L1中元素大，合并L2中元素到L3中
            L3->elem[k ++ ] = L2->elem[j ++ ];
        }else if (L1->elem[i] == L2->elem[j]){
            L3->elem[k ++ ] = L2->elem[j ++ ]; // 元素相等，只保留一个，合并到L3中
            i ++ ;
        }else{ // L2中元素大，合并L1中元素到L3中
            L3->elem[k ++ ] = L1->elem[i ++ ];
        }    
        L3->length ++ ;
    }

    while (i < L1->length) { // L2结束，合并L1中元素到L3中
        L3->elem[k ++ ] = L1->elem[i ++ ];
        L3->length ++ ;
    }

    while (j < L2->length) { // L1结束，合并L2中元素到L3中
        L3->elem[k ++ ] = L2->elem[j ++ ];
        L3->length ++ ;
    }
}


// 方法二
void merge(SqList *A, SqList *B, SqList *C) {
    if (A->length + B->length > C->listsize) return;
    int i = 0, j = 0, k = 0;
    while (i < A->length && j < B->length) {
        if (A->elem[i] <= B->elem[j]) {
            C->elem[k ++ ] = A->elem[i ++ ];
        }else {
            C->elem[k ++ ] = B->elem[j ++ ];
        }
    }
    while (i < A->length) {
        C->elem[k ++ ] = A->elem[i ++ ];
    }
    while (j < B->length) {
        C->elem[k ++ ] = B->elem[j ++ ];
    }

    C->length = k;
}


int main()
{
    SqList L1, L2, L3, L4;
    InitList(&L1);
    ListInsert(&L1, 1, 1);
    ListInsert(&L1, 2, 4);
    ListInsert(&L1, 3, 6);

    InitList(&L2);
    ListInsert(&L2, 1, -1);
    ListInsert(&L2, 2, 0);
    ListInsert(&L2, 3, 2);
    ListInsert(&L2, 4, 8);
   
    
    InitList(&L3);

    Combination(&L1, &L2, &L3);
    ListPrint(&L3);

    printf("=======================\n");

    InitList(&L4);
    merge(&L1, &L2, &L4);

    ListPrint(&L4);
    return 0;
}