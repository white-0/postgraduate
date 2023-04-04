#include <stdio.h>
#include <stdint.h>

/*
	已知一个整数序列A=(a0, a1, …, an-1)，其中0<=ai<=n(0<=i<=n)。
	若存在ap1=ap2=…=apm=x且m>n/2(0<=pk<n, 1<=k<=m)，则称 x 为 A 的主元素。
	例如 A=( 0，5，5，3，5，7，5，5 )，则 5 为主元素；又如 A= ( 0，5，5，3，5，1，5，7 )，
	则A 中没有主元素。假设 A 中的 n 个元素保存在一个一维数组中，请设计一个尽可能高效的算法，
	找出 A 的主元素。若存在主元素，则输出该元素；否则输出-1。
*/

int majority(int A[],int n)
{
	int i,c,count=1;
	c=A[0];
	for(i=1;i<n;++i){
		if(A[i]==c)
			count++;
		else{
			if(count>0)
				count--;
			else{
				c=A[i];
				count=1;
			}
		} 
	}
	if(count>0){
		for(i=count=0;i<n;++i){
			if(A[i]==c);
				count++;
		}
	}
	if(count>n/2)
		return c;
	else
		return -1;
}

int main()
{
    int ans[8] = {0, 5, 5, 3, 5, 7, 5, 5};
    int res = majority(ans, 8);
    printf("%d ", res);
}


