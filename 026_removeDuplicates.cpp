//26. 删除有序数组中的重复项
//
//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

//Tips:
//双指针

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	int sz = nums.size();
	if (sz == 0) return 0;
	if (sz == 1) return 1;

	int slow = 1, fast = 1;
	while (fast < sz) {
		if (nums[fast] != nums[fast - 1]) {
			nums[slow] = nums[fast];
			++slow;
		}
		++fast;
	}
	return slow;
}


int main() {
	

	return 0;
}
