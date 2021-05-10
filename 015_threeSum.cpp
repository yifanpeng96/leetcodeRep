//15. 三数之和
//
//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
//
//请你找出所有和为 0 且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	int sz = nums.size();
	if (sz < 3) return {};

	//递增排序
	sort(nums.begin(), nums.end());
	
	vector<vector<int>> ans;
	for (int i = 0; i != sz; ++i) {
		if (nums[i] > 0) return ans;
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		//双指针, 在nums[i]后面的区间中寻找x, y, 使得x + y == -nums[i]
		int left = i + 1, right = sz - 1;
		while (left < right) {
			if (nums[left] + nums[right] < -nums[i])
				++left;
			else if (nums[left] + nums[right] > -nums[i])
				--right;
			else {
				//nums[i], nums[left], nums[right]依次递增
				ans.push_back({ nums[i], nums[left], nums[right] });
				//并未结束, 继续寻找其他的和为-nums[i]的x和y
				++left, --right;
				//防止ans中加入相同的vector串, 去重
				while (left < right && nums[left] == nums[left - 1])
					++left;
				while (left < right && nums[right] == nums[right + 1])
					--right;
			}
		}
	}
	return ans;
}

int main() {
	

	return 0;
}
