#include <stdio.h>
#include <stdint.h>
/*
	设将 n（n>1）个整数存放到一维数组 R 中。
	试设计一个在时间和空间两方面都尽可能高效的算法。
	将 R 中保存的序列循环左移 p（0<p<n）个位置，
	即将 R 中的数据由（X0, X1…Xn-1）变换为（Xp, Xp+1 …Xn-1, X0, X1…Xp-1）
*/
void Reverse(int R[],int from,int to) { 
    int i,temp; 
    for(i = 0; i < (to-from+1)/2; i++){ 
        temp = R[from+i]; 
        R[from+i] = R[to-i]; 
        R[to-i] = temp; 
    } 
} // Reverse 
void Converse(int R[],int n,int p){ 
    Reverse(R,0,p-1);  
    Reverse(R,p,n-1); 
    Reverse(R,0,n-1); 
}

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Converse(arr, 10, 3);
    int i;
    for (i = 0; i < 10; i ++ ) printf("%d ", arr[i]);
}