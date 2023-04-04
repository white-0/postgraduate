#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 试写一算法，实现顺序表的就地逆置
// ，即利用原表的存储空间将线性表(a1,a2,a3,…,an)逆置为(an,an-1,…a2,a1)。
void reverse (int a[], int size) {
    int i, j, tmp;
    for (i = 0, j = size - 1; i < j; i ++, j -- ) {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

int main()
{
    int i;
    int a[5] = {-1, 2, 0, -3, -4};
    int size = sizeof(a) / sizeof(a[0]);
    reverse (a, size);
    for (i = 0; i < size; i ++ ) printf("%d ", a[i]);
    return 0;
}