#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 已知在一维数组A[0，…，m+n-1]中依次存放着两个顺序表（a1，a2，…,am)
// 和(b1,b2，…，bn )。试编写程序，将数组中两个顺序表的位置互换，
// 即将(b1，b2，…，bn)放在(a1，a2，…，am）的前面。
void Reverse(int A[], int left, int right, int arraySize) {
    if (left >= right || right >= arraySize) return;
    int mid = (left + right) / 2;
    int i ;
    for (i = 0; i <= mid - left; i ++ ) {
        int temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

void Exchange(int A[], int m, int n, int arraySize) {
    
    Reverse(A, 0, m + n - 1, arraySize);
    Reverse(A, 0, n - 1, arraySize);
    Reverse(A, n, m + n - 1, arraySize);
    
}

int main()
{
    int i;
    int a[5] = {-1, 2, 0, -3, -4};
    int size = sizeof(a) / sizeof(a[0]);

    Exchange(a, 3, size - 3, size);
    for (i = 0; i < size; i ++ ) printf("%d ", a[i]);
    return 0;
}