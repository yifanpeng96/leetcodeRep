//62. 不同路径
//
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//
//问总共有多少条不同的路径？

//Tips:
//动态规划: 机器人从左上角到[i, j]格有 dp[i][j] 种不同的路径
//状态转移方程 dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
//边界条件 dp[0][j] = dp[i][0] = 0

//必须要先定义vector的大小为 m * n
//动态分配是在加入元素时再分配空间，即没加入前空间还没有分配，所以不允许使用下标操作，
//因为下标指向的位置并不存在。所以先提前定义容器的大小，这是提前分配好空间，分配后，
//里面的数会默认初始化，也就可以使用下标访问了，但是得注意和数组一样，下标不得越界。

#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, 0)); //初始化m * n矩阵, 初始值为0
	
	//第0行和第0列上所有格路径都只有1种
	for (int i = 0; i != m; ++i)
		dp[i][0] = 1;
	for (int j = 0; j != n; ++j)
		dp[0][j] = 1;
	
	for (int i = 1; i != m; ++i) {
		for (int j = 1; j != n; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}

	return dp[m - 1][n - 1];
}

int main() {
	
	
	return 0;
}
