#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
	已知由n(n>=2)个正整数构成的集合A={ak|0<=k<n}, 
	将其划分为两个不相交的子集A1和A2, 元素个数分别是n1和n2,
	A1和A2中元素之和分别为S1和S2, 设计一个尽可能高效的划分算法, 
	满足| n1- n2|最小且| S1- S2|最大。要求
*/
int setPartition(int a[], int n) {
    int pivotkey, low = 0, low0 = 0, high = n - 1, high0 = n - 1;
    int flag = 1, k = n / 2, I;
    int s1 = 0, s2 = 0;
    while (flag) {
        pivotkey = a[low];
        while (low < high) {
            while (low < high && a[high] >= pivotkey) -- high;
            if (low != high) a[low] = a[high];
            while (low < high && a[low] <= pivotkey) ++ low;
            if (low != high) a[high] = a[low];
        }
        a[low] = pivotkey;
        if (low == k - 1) flag = 0;
        else {
            if (low < k - 1) {
                low0 = ++ low;
                high = high0;
            }else {
                high0 = -- high;
                low = low0;
            }
        }
    }
    int i;
    for (i = 0; i < k; i ++ ) s1 += a[i];
    for (i = k; i < n; i ++ ) s2 += a[i];

    return s2 - s1;
}

int main()
{
    int arr[10] = {1, 100, 3, 4, 5, 23, 7, 11, 9, 10};
    int res = setPartition(arr, 10);
    int i;
    for (i = 0; i < 10; i ++ ) printf("%d ", arr[i]);
    printf("\n");
    printf("%d\n", res);
    return 0;
}