#include <stdio.h>
#include <stdlib.h>

/*
	假设按照升序排序的数组在预先未知的某个点上进行了旋转。
	( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
	搜索一个给定的目标值，如果数组中存在这个目标值，
	则返回它的索引，否则返回 -1 。假设数组中不存在重复的元素
*/

int binarySearch(int nums[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int search(int nums[], int n, int target) {
        //使用二分法
        if (n == 0 || nums == NULL) return -1;
        //先用二分法找到分界点
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        //分界点为Left
        int split = left;
        //如果没有分界点，采用普通的二分法
        if (split == 0)
            return binarySearch(nums, 0, n - 1, target);
        //判断target在哪个范围
        left = 0;
        right = n-1;
        if (target >= nums[split] && target <= nums[right]) {
            left = split;
        } else {
            left = 0;
            right = split;
        }
        //二分法查找
        return binarySearch(nums, left, right, target);
    }


int main()
{
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int res = search(arr, 7, target);
    printf("%d ", res);   
}