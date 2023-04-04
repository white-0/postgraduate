#include <stdio.h>
#include <stdlib.h>

// 对于一个数组，将数组中负数的放左边，正数放右边。

void partition(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < right && arr[left] < 0) left ++ ;
        while (left < right && arr[right] > 0) right -- ;
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
}

int main() {
    int i, arr[5] = {1, -1, 2, -9, 10};
    partition(arr, 5);
    for (i = 0; i < 5; i ++ ) printf("%d ", arr[i]);
    printf("\n");
}