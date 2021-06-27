//63. 不同路径 II
//
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//
//网格中的障碍物和空位置分别用 1 和 0 来表示。

//Tips:
//动态规划
//状态转移方程 dp[i][j] = dp[i - 1][j] + dp[i][j - 1], 注意障碍物

#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size(); //行
	int n = obstacleGrid[0].size(); //列
	
	if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		return 0;

	vector<vector<int>> dp(m, vector<int>(n, 0));

	for (int i = 0; i != m; ++i) {
		if (obstacleGrid[i][0]) {
			for (int iDown = i; iDown != m; ++iDown)
				dp[iDown][0] = 0;
			break;
		}
		dp[i][0] = 1;
	}
	for (int j = 0; j != n; ++j) {
		if (obstacleGrid[0][j]) {
			for (int jDown = j; jDown != n; ++jDown)
				dp[0][jDown] = 0;
			break;
		}
		dp[0][j] = 1;
	}

	for (int i = 1; i != m; ++i) {
		for (int j = 1; j != n; ++j) {
			if (obstacleGrid[i][j]) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[m - 1][n - 1];
}

int main() {
	
	
	return 0;
}
