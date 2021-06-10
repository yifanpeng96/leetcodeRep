//47. 全排列 II
//
//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

//Tips:
//回溯法

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//维护一个检查重复的哈希表
vector<bool> visited;

void backtrack(vector<vector<int>>& ans, vector<int>& nums, int idx, vector<int>& oneAns) {
	if (idx == nums.size()) {
		ans.push_back(oneAns);
		return;
	}
	for (int i = 0; i != nums.size(); ++i) {
		//如果是重复的数字则跳过
		if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
			continue;
		oneAns.push_back(nums[i]);
		visited[i] = true;
		backtrack(ans, nums, idx + 1, oneAns);
		visited[i] = false;
		oneAns.pop_back();
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> oneAns;
	visited.resize(nums.size());
	//排序, 保证重复的数字相邻
	sort(nums.begin(), nums.end());
	backtrack(ans, nums, 0, oneAns);
	return ans;
}

int main() {
	

	return 0;
}
