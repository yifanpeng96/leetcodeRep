//34. 在排序数组中查找元素的第一个和最后一个位置
//
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回 [-1, -1]。
//
//进阶：
//
//你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

//Tips:
//二分法
//模版: 都写l = mid或者r = mid，mid首先写成l + r >> 1，如果满足条件选择的是l = mid，
//     那么mid那里就加个1，写成l + r + 1 >> 1。然后就是else对应的写法l = mid对应r = mid - 1，
//     r = mid对应l = mid + 1。

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	int sz = nums.size();
	if (sz == 0) return { -1,-1 };
	if (sz == 1 && target == nums[0]) return { 0, 0 };
	if (sz == 1 && target != nums[0]) return { -1, -1 };

	int left = 0, right = sz - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			int head = mid, end = mid;
			while (head - 1 >= 0 && nums[head - 1] == target)
				--head;
			while (end + 1 < sz && nums[end + 1] == target)
				++end;
			return { head, end };
		}
		else if (nums[mid] > target) //目标值在左侧
			right = mid - 1;
		else //目标值在右侧
			left = mid + 1;
	}
	return { -1,-1 };
}

int main() {


	return 0;
}
