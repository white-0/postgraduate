#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ElemType int

ElemType array[20] = {0, 1, 4, 7, 9, 13, 16, 12, 23, 43};
int n;

// 线性表(a1,a2,a3，… an)中元素递增有序且按顺序存储于计算机内。
// 要求设计一算法完成用最少时间在表中查找数值为x的元素，
// 若找到将其与后继元素位置相交换，
// 若找不到将其插入表中并使表中元素仍递增有序。
void SearchExchangeInsert(ElemType A[], ElemType x) {
    int low = 0, high = n - 1, mid;
    while (low <= high) { // 折半方法查找元素
        mid = (low + high) / 2;
        if (A[mid] == x) break;
        else if (A[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    if (A[mid] == x && mid != n - 1) { // 如果存在，交换X和他的后继
        int t = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = t;
    }
    if (low > high) { // 如果不存在，把大于X的元素后移，并插入X
        int i;
        for (i = n; i > high; i -- ) A[i + 1] = A[i];
        A[i + 1] = x;
    }   
}


int main()
{
    int i;

    n = sizeof(array) / sizeof(array[0]);
    
    SearchExchangeInsert(array, 20);
	
	n = sizeof(array) / sizeof(array[0]);
	 
    for (i = 0; i < n; i ++ )
        printf("%d ", array[i]);
	printf("\n");
	
	n = sizeof(array) / sizeof(array[0]);
	
	SearchExchangeInsert(array, 2);
    for (i = 0; i < n; i ++ )
        printf("%d ", array[i]);
    return 0;
}