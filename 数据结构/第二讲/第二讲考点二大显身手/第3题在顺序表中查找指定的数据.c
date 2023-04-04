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

// 请写一算法，在顺序表中查找指定的数据，
// 查找成功则将该记录放到顺序表的最前面，
// 而把其他记录后退到某个位置
void searchValue(SqList *head, ElemType x) {
    int i, j;
    for (i = 0; i < head->length; i ++ ) {
        if (i != 0 && head->elem[i] == x) {
            for (j = i - 1; j >= 0; j -- ) {
                head->elem[j + 1] = head->elem[j];
            }
            head->elem[0] = x;
        }
    }
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
    ListInsert(&L1, 4, -8);

    ListPrint(&L1);

    searchValue(&L1, -8);

    ListPrint(&L1);
    return 0;
}