#include <stdio.h>
#include <stdlib.h>

// 给定一个数组，求出一个算法，实现数组逆置
void reverse(int arr[], int n) {
    int i;
    for (i = 0; i < n / 2; i ++ ) {
        int temp = arr[i];
        arr[i] = arr[n - 1- i];
        arr[n - 1 - i] = temp;
    }
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    reverse(a, 4);
    int i;
    for (i = 0; i < 4; i ++ ) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}