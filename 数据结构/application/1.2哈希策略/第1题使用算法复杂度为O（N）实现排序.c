#include <stdio.h>
#include <stdlib.h>

// 使用算法复杂度为O（N）实现排序，其中N是元素个数，且元素大小不超过n。
 
void SortByN(int a[], int length)
{
	if (a == NULL || length < 0) return;
	//重新申请一个数组
	const int N =200;
	int b[N];
    int i, j;
	//把新申请的数组全部初始化为0
	for (i = 0; i < N; ++i) {
		b[i] = 0;
	}
	//遍历a数组
	for (i = 0; i < length; ++i) {
	//例如：a[0] = 10;那么b[key] = b[10] = 1;表示有一个10； a[4] = 10;
	//那么b[key] = b[10] = 1+1 = 2,表示此时有两个10；
	int key = a[i];
	++b[key];
    //意思就是b数组里面存放的是a数组中某个元素的个数，b[10]表示在a数
    //组当中10出现的次数，b[0]表示0在a数组当中出现的次数
	}
	int index = 0;
	for (i = 0; i < N; ++i) {
	//如果b[0] = 0;表示a数组当中没有0；那么不执行这个循环；
	//那么b[0] --b[17]都是等于0；那么第二个循环都不执行，第一个循环执行，i加到了18；b[18]=2；
	//那么a数组当中有两个18；而且这两个18就是最小的数字，那么a[0] = 18; a[1] = 18;
		for (j = 0; j < b[i];++j) {
			a[index] = i;
			++index;
		}
	}
}

int main() {
    int a[10] = {8, 0, 9, 100, 3, 5, 8, 7, 6};
    SortByN(a, 10);
    int i;
    for (i = 0; i < 10; i ++ ) printf("%d ", a[i]);
    return 0;
}