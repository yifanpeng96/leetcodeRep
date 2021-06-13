//53. 最大子序和
//
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

//Tips:
//动态规划: dp[i] 指以第i个元素结尾的最大子序和
//         状态转移方程为 dp[i] = max{dp[i - 1] + nums[i], nums[i]}

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int sz = nums.size();
	if (sz == 1) return nums[0];

	int dp = 0;
	int ans = nums[0];

	for (int i = 0; i != sz; ++i) {
		dp = max(dp + nums[i], nums[i]);
		ans = max(ans, dp);
	}
	return ans;
}

int main() {
	

	return 0;
}
