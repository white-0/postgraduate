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

// 顺序表va( 下标从0 开始）中的数据元数递增有序。
// 试写一算法，将x 插入到顺序表的适当位置上，以保持该表的有序性
void InsertSqList(SqList *va, int x) {
    if (va->length >= MAX_SIZE) return;
    int i;
    for (i = va->length - 1; va->elem[i] > x && i >= 0; i -- )
        va->elem[i + 1] = va->elem[i];
    va->elem[i + 1] = x;
    va->length ++ ;
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

    InsertSqList(&L1, 8);
    InsertSqList(&L1, 1);
    InsertSqList(&L1, 3);
    InsertSqList(&L1, 7);

    ListPrint(&L1);
    return 0;
}