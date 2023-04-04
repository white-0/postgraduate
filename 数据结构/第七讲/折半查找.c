#include <stdio.h>

int bin_Search(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main()
{
    int a[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int res = bin_Search(a, 10, 7);
    printf("%d", res);
    return 0;
}