#include <stdio.h>

// 插入排序
void insert_sort(int A[], int n) {
    int i;
    for (i = 1; i < n; i ++ ) {
        if (A[i] < A[i - 1]) {
            int temp = A[i], j;
            for (j = i - 1; j >= 0 && A[j] > temp; j -- )
                A[j + 1] = A[j];
            A[j + 1] = temp;
        }
    }
}

// 折半插入排序
void bin_insert_sort(int A[], int n) {
    int i;
    for (i = 1; i < n; i ++ ) {
        int temp = A[i];
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] > temp) high = mid - 1;
            else low = mid + 1;
        }
        int j;
        for (j = i - 1; j >= low; j -- )
            A[j + 1] = A[j];
        A[low] = temp;
    }
}

// 冒泡排序
void bubble_sort(int A[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i ++ ) {
        for (j = 0; j < n - i - 1; j ++ ) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// 选择排序
void select_sort(int A[], int n) {
    int i, j, k;
    for (i = 0; i < n; i ++ ) {
        int minValue = A[i];
        for (int j = i; j < n; j ++ ) {
            if(minValue > A[j]) {
                int temp = A[j];
                A[j] = minValue;
                minValue = temp;
            }
        }
        A[i] = minValue;
    }
}

// 希尔排序
void shell_sort(int A[], int n) {
    int d, i, j;
    for(d = n / 2; d > 0; d /= 2) {
        for (i = d; i < n; i ++ ) {
            int temp = A[i];
            j = i - d;
            while (j >= 0 && A[j] > temp) {
                A[j + d] = A[j];
                j -= d;
            }
            A[j + d] = temp;
        }
    }
}

// 快速排序
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x); 
        if (i < j) {
            int temp = q[i];
            q[i] = q[j];
            q[j] = temp;
        }
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

// 归并排序
int tmp[10];
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] < q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];
    }
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ )q[i] = tmp[j];
}

int main()
{
    int q[10] = {10, 2, 4, 3, 7, 1, 6, 5, 9, 11};
    insert_sort(q, 10);
    int i;
    for (i = 0; i < 10; i ++ ){
        printf("%d ", q[i]);
    }
    printf("\n");
    return 0;
}