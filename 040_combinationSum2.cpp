//40. 组合总和 II
//
//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用一次。
//
//说明：
//
//所有数字（包括目标数）都是正整数。
//解集不能包含重复的组合。

//Tips:
//回溯

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans,
	vector<int>& oneAns, int idx) {
	if (target == 0) {
		ans.push_back(oneAns);
			return;
	}
	for (int i = idx; i < candidates.size() && target - candidates[i] >= 0; ++i) {
		//防止重复
		if (i > idx && candidates[i] == candidates[i - 1])
			continue;
		oneAns.push_back(candidates[i]);
		dfs(candidates, target - candidates[i], ans, oneAns, i + 1);
		oneAns.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> oneAns;
	sort(candidates.begin(), candidates.end());
	dfs(candidates, target, ans, oneAns, 0);
	return ans;
}

int main() {
	

	return 0;
}
