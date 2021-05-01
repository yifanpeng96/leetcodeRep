//1. 两数之和
//
//给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//
//你可以按任意顺序返回答案。

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	if (nums.empty())
		return {};

	unordered_map<int, int> diffVal;
	int sz = nums.size();
	for (int i = 0; i != sz; ++i) {
		if (diffVal.find(target - nums[i]) == diffVal.end())
			diffVal.insert(pair<int, int>(nums[i], i));
		else {
			return { diffVal[target - nums[i]], i };
		}
	}
	return {};
}

int main() {


	return 0;
}
