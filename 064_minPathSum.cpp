//64. 最小路径和
//
//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。

//Tips:
//动态规划
//状态转移方程 dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]

#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size(); //行
	int n = grid[0].size(); //列

	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = grid[0][0];

	for (int i = 1; i != m; ++i)
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	for (int j = 1; j != n; ++j)
		dp[0][j] = dp[0][j - 1] + grid[0][j];

	for (int i = 1; i != m; ++i) {
		for (int j = 1; j != n; ++j)
			dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
	}

	return dp[m - 1][n - 1];
}

int main() {
	
	
	return 0;
}
