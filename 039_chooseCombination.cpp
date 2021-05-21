//39. 组合总和
//
//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的数字可以无限制重复被选取。
//
//说明：
//
//所有数字（包括 target）都是正整数。
//解集不能包含重复的组合。 

//Tips:
//DFS算法
//我们定义递归函数 dfs(target, combine, idx) 表示当前在 candidates 数组的第 idx 位，
//还剩 target 要组合，已经组合的列表为 combine。递归的终止条件为 target <= 0 或者 candidates 数组
//被全部用完。那么在当前的函数中，每次我们可以选择跳过不用第 idx 个数，即执行 
//dfs(target, combine, idx + 1)。也可以选择使用第 idx 个数，即执行 dfs(target - candidates[idx], combine, idx)，
//注意到每个数字可以被无限制重复选取，因此搜索的下标仍为 idx。

#include <iostream>
#include <vector>
using namespace std;

void chooseCombination(vector<int>& candidates, int target,
	vector<vector<int>>& ans, vector<int>& oneAns, int idx) {
	if (idx == candidates.size())
		return;
	if (target == 0) {
		ans.push_back(oneAns);
		return;
	}
	//第一种选择: 直接跳过当前数candidates[idx]
	chooseCombination(candidates, target, ans, oneAns, idx + 1);

	//第二种选择: 选择当前数candidates[idx]为组合target的数
	if (target - candidates[idx] >= 0) {
		oneAns.push_back(candidates[idx]);
		//因为组合数可以重复选取, 所以这里的idx不用+1
		chooseCombination(candidates, target - candidates[idx], ans, oneAns, idx);
		//要舍弃candidates[idx]以回溯到上一层
		oneAns.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> oneAns;
	chooseCombination(candidates, target, ans, oneAns, 0);
	return ans;
}

int main() {
	

	return 0;
}
