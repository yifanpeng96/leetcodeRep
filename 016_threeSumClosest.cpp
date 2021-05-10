//16. 最接近的三数之和
//
//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
//
//使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	int sz = nums.size();
	//排序
	sort(nums.begin(), nums.end());

	int abs_diff = INT_MAX, sum = nums[0] + nums[1] + nums[2];
	for (int i = 0; i != sz - 2; ++i) {
		if (nums[i] > target / 3)
			return sum;

		//双指针, 寻找target - nums[i]与x + y最接近的数
		int left = i + 1, right = sz - 1;
		while (left < right) {
			int diff = nums[left] + nums[right] + nums[i] - target;
			if (diff == 0)
				return target;
			else {
				if (abs(diff) < abs_diff) {
					abs_diff = abs(diff);
					sum = nums[left] + nums[right] + nums[i];
				}

				if (diff > 0) {
					--right;
					while (left < right && nums[right + 1] == nums[right]) --right;
				}
				else {
					++left;
					while (left < right && nums[left - 1] == nums[left]) ++left;
				}
			}
		}
	}
	return sum;
}

int main() {
	

	return 0;
}
