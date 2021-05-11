//18. 四数之和
//
//给定一个包含n个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
//
//使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
//注意：答案中不可以包含重复的四元组。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int sz = nums.size();
	if (sz < 4) return {};

	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;

	for (int i = 0; i != sz - 3; ++i) {
		for (int j = i + 1; j != sz - 2; ++j) {
			int left = j + 1, right = sz - 1;
			while (left < right) {
				if (nums[i] > target / 4)
					return ans;
				
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum == target) {
						ans.push_back({ nums[i], nums[j], nums[left], nums[right] });
					++left;
					while (left < right && nums[left - 1] == nums[left]) ++left;
					--right;
					while (left < right && nums[right + 1] == nums[right]) --right;
				}
				else if (sum < target) {
					++left;
					while (left < right && nums[left - 1] == nums[left]) ++left;
				}
				else {
					--right;
					while (left < right && nums[right + 1] == nums[right]) --right;
				}
			}
			while (j + 1 < sz - 2 && nums[j] == nums[j + 1]) ++j;
		}
		while (i + 1 < sz - 3 && nums[i] == nums[i + 1]) ++i;
	}
	return ans;
}

int main() {
	

	return 0;
}
