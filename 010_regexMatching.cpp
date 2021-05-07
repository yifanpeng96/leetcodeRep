//10. 正则表达式匹配
//
//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
//所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

//Tips:
//1. 动态规划, 用dp[i][j]表示s的前i个字符与p的前j个字符是否匹配
//2. 状态转移方程为:
//     dp[i][j] = dp[i - 1][j - 1]               if p[j] != '*' && 第i个s和第j个p匹配
//                false                          if p[j] != '*' && 第i个s和第j个p不匹配
//                dp[i - 1][j] || dp[i][j - 2]   if p[j] == '*' && 第i个s和第j个p匹配
//                dp[i][j - 2]                   if p[j] == '*' && 第i个s和第j个p不匹配

#include <string>
#include <vector>
using namespace std;

//s[i - 1]和p[j - 1]是否匹配, 因为i表示s的前i个字符, 所以第i个字符为s[i - 1]
bool matches(int i, int j, string& s, string& p) {
	if (i == 0)
		return false;
	if (p[j - 1] == '.')
		return true;
	return s[i - 1] == p[j - 1];
}

bool isMatch(string s, string p) {
	int m = s.size(), n = p.size();

	vector<vector<bool>> dp(m + 1, vector<bool>((n + 1), false));
	dp[0][0] = true;//s和p都为空字符串时为true

	for (int i = 0; i != m + 1; ++i) {
		for (int j = 1; j != n + 1; ++j) {
			if (p[j - 1] != '*') {
				if (matches(i, j, s, p))
					dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				if (matches(i, j - 1, s, p))
					dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
				else
					dp[i][j] = dp[i][j - 2];
			}
		}
	}
	return dp[m][n];
}

int main() {
	

	return 0;
}
