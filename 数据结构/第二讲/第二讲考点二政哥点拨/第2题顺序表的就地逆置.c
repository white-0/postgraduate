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


// 试写一算法，实现顺序表的就地逆置，
// 即利用原表的存储空间将线性表(a1,a2,a3,…,an)逆置为(an,an-1,…a2,a1)。
int ListOppose(SqList* L)
{
    int i;
    ElemType x;
	// 只需要遍历原表的一半就可以实现数据元素位置的交换
    for (i = 0; i < L->length / 2; i ++ ) {
        x = L->elem[i];
        L->elem[i] = L->elem[L->length - i - 1];
        L->elem[L->length - i - 1] = x;
    }
    return 1;
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
    ListInsert(&L1, 2, 0);
    ListInsert(&L1, 3, 2);
    ListInsert(&L1, 4, 8);
	ListInsert(&L1, 5, 10);

    ListPrint(&L1);
    ListOppose(&L1);
    ListPrint(&L1);
    return 0;
}