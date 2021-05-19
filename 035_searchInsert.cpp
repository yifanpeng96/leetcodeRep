//35. 搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。

//Tips:
//二分法

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int n = nums.size();
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] < target)
			l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int main() {
	

	return 0;
}
