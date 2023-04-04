#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE 100            // 数组最大长度
typedef int ElemType;           // 数组类型的别名
typedef struct sqlist           // 定义线性表结构体
{
    ElemType* data;             // 线性表存储元素的数组
    int length;                 // 记录线性表长度
}Sqlist;                        // 线性表的名称

// 顺序表初始化
void InitList(Sqlist *L)
{
	L->data = (ElemType *)malloc(MAX_SIZE * sizeof(ElemType));
	if(!L->data)
	{
		printf("存储空间分配失败!");
	}
	L->length = 0;
}

// 顺序表查找
int FindByValue(Sqlist* L, ElemType e) {
    int i;
    for (i = 0; i < L->length; i ++ )
        if (L->data[i] == e)
            return i + 1;
    return 0;
}


// 顺序表插入
int ListInsert(Sqlist *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return 0;
    if (L->length >= MAX_SIZE) return 0;

    int j;
    for (j = L->length; j >= i; j -- )
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length ++ ;
    return 1;
}

// 顺序表按位删除
int ListDelete(Sqlist *L, int i) {
    if (L->length == 0)  return 0;

    if (i < 1 || i > L->length) return 0;
    //*e = L->data[i - 1];
    int j;
    for (j = i; j < L->length; j ++ )
        L->data[j - 1] = L->data[j];
    L->length -- ;
    return 1;
}

// 顺序表查找定位删除
int Locate_Delete_SqList(Sqlist *L, int x) {
    // 删除线性表L中值为x的第一个结点
    int i = 0, k;
    while (i < L->length) {
        if (L->data[i] != x) i ++ ;
        else {
            for (k = i + 1; k < L->length; k ++ )
                L->data[k - 1] = L->data[k];
            L->length -- ;
            break;
        }
    }
    if (i > L->length) { printf("要删除的数据元素不存在！\n"); return 0;}
    return 1;
}

void ListPrint(Sqlist* L) {
    int i;
    for (i = 0; i < L->length; i ++ )
        printf ("index = %d, data =  %d\n", i, L->data[i]);
    printf("\n");
}


int main()
{
    Sqlist L;
    InitList(&L);
    
    ListInsert(&L, 1, 2);
    ListInsert(&L, 2, 4);
    ListPrint(&L);

    ListInsert(&L, 3, 8);
    ListPrint(&L);

    ListDelete(&L, 2);
    ListPrint(&L);


    Locate_Delete_SqList(&L, 8);
    ListPrint(&L);

    printf("%d", FindByValue(&L, 2));
	printf("\n%d", FindByValue(&L, 8));
    return 0;
}
