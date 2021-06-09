//44. 通配符匹配
//
//给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
//
//'?' 可以匹配任何单个字符。
//'*' 可以匹配任意字符串（包括空字符串）。
//
//两个字符串完全匹配才算匹配成功。
//
//说明 :
//
//s 可能为空，且只包含从 a - z 的小写字母。
//p 可能为空，且只包含从 a - z 的小写字母，以及字符  ? 和  * 。

//Tips:
//动态规划
//用 dp[i][j] 表示字符串 s 的前 i 个字符和模式 p 的前 j 个字符是否能匹配
//状态转移方程为:
//dp[i][j] = dp[i - 1][j - 1]  if s[i] == p[j] || p[j] == '?'
//           dp[i][j - 1] || dp[i - 1][j]  if p[j] == '*'
//           false  otherwise
//边界条件要考虑 dp[0][j] 和 dp[i][0] , 为: dp[i][0] == false  恒定
//                                        dp[0][j] == true  if p[0] ~ p[j] == '*'
//                                                    false  otherwise
//因此可将dp的默认值设为false

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
	if (p == "*") return true;
	
	int s_sz = s.size();
	int p_sz = p.size();
	//初始化一个 s_sz + 1 * p_sz + 1 的dp
	vector<vector<bool>> dp(s_sz + 1, vector<bool>(p_sz + 1, false));
	dp[0][0] = true;
	//dp[0][j]的边界条件
	for (int j = 1; j <= p_sz; ++j) {
		if (p[j - 1] == '*')
			dp[0][j] = true;
		else
			break;
	}
	
	for (int i = 1; i <= s_sz; ++i) {
		for (int j = 1; j <= p_sz; ++j) {
			//状态转移方程
			if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else if (p[j - 1] == '*')
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
		}
	}
	return dp[s_sz][p_sz];
}

int main() {
	

	return 0;
}
