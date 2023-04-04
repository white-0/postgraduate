#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 给定一个含n（n>=1）个整数的数组，请设计一个在时间上尽可能高效的算法，
// 找出数组中未出现的最小正整数。
int findMissMin(int A[],int n){
    int i,*B;//标记数组
    B = (int *)malloc(sizeof(int)*n);   //分配空间
    memset(B,0,sizeof(int)*n);    //赋初值为0
    for(i = 0;i < n;i++){
        if(A[i] > 0 && A[i] <= n)  //若A[i]的值介于1~n，则标记数组B
            B[A[i]-1] = 1;
    }
    for(i = 0;i<n;i++) {    //扫描计数数组，找到目标值K
        if(B[i] == 0) break;
    }
    return i + 1;   //返回结果
}

int main()
{
    int arr[5] = {1, 2, 5, 3, 6};
    int res = findMissMin(arr, 5);
    printf("%d", res);
    return 0;
}