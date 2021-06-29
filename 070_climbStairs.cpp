//70. 爬楼梯
//
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//注意：给定 n 是一个正整数。

//Tips:
//设dp[i]为爬i阶的方法. 则dp[i] = dp[i - 1] + dp[i - 2]
//可用常数替代数组节省空间

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;

	vector<int> dp(n + 1, 0);
	dp[1] = 1, dp[2] = 2;

	for (int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	
	return dp[n];
}

int main() {


	return 0;
}
