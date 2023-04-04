#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 设有一个线性表存放在一维数组a[0..n -1]中，
// 编程将数组中每一个元素循环右移k位，
// 要求只用一个辅助单元，时间复杂度为0(n)。

void Reverse(int* array, int p, int q) { // 这一步是实现数组逆置
    for (; p < q; p ++, q -- ){
        int temp = array[p];
        array[p] = array[q];
        array[q] = temp;
    }
}

void RightShift(int* array, int n, int k) {
    k %= n;
    
    Reverse(array, 0, n - 1);
    Reverse(array, 0, k - 1);
    Reverse(array, k, n - 1);
}

int main()
{
    int i;
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(a) / sizeof(a[0]);
    for (i = 0; i < size; i ++ ) printf("%d ", a[i]);
    printf("\n");
    RightShift(a, size, 3);
    for (i = 0; i < size; i ++ ) printf("%d ", a[i]);
    return 0;
}