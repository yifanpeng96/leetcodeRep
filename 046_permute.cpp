//46. 全排列
//
//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

//Tips:
//回溯法

#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& ans, vector<int>& oneAns, int start, int sz) {
	if (start == sz) {
		ans.push_back(oneAns);
		return;
	}
	for (int i = start; i != sz; ++i) {
		swap(oneAns[i], oneAns[start]);
		backtrack(ans, oneAns, start + 1, sz);
		//回溯后注意撤销操作
		swap(oneAns[i], oneAns[start]);
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ans;
	backtrack(ans, nums, 0, nums.size());
	return ans;
}

int main() {
	

	return 0;
}
