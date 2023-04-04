#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 已知线性表(a1 ，a2，...,an ) 按顺序结构存储且每个元素为不相等的整数。 
// 设计把所有奇数移到所有偶数前边的算法（要求时间最少，辅助空间最少）
void part(int array[], int n) {
    int i, j;
    i = 0, j = n - 1;
    while (i < j) {
        while (i < j && array[i] % 2 != 0) i ++ ; // i 指针从前往后扫描数组，遇到偶数停下
        while (i < j && array[j] % 2 == 0) j -- ; // j 指针从后往前扫描数组，遇到奇数停下
        if (i < j) {                              // i < j 交换两个指针分别指向的元素
            int t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
    }
}

int main()
{
    int array[10] = {1, 3, 1, 7, 2, 4, 5, 2, 9, 8};
    part(array, 10);
    int i;
    for (i = 0; i < 10; i ++ )
        printf("%d ", array[i]);
    return 0;
}