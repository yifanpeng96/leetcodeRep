//32. 最长有效括号
//
//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

//Tips:
//动态规划 dp[i] 0~i个字符的子串中 以i字符结尾 的最长有效的长度 则如果i字符为'('的话dp必为0
//从前往后遍历s, 每2个字符检查一次
//1. 若 s[i] = ')' && s[i - 1] = '(' 时, dp[i] = dp[i − 2] + 2
//2. 若 s[i] = ')' && s[i - 1] = ')' 时, 如果dp[i - 1]的最长子串前一位(即i - dp[i - 1] - 1)
//   的字符为'('的话, dp可+2, 所以dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
	if (s == "") return 0;

	int maxAns = 0, sz = s.size();
	vector<int> dp(sz, 0);

	for (int i = 1; i != sz; ++i) {
		if (s[i] == ')') {
			if (s[i - 1] == '(') {
				if (i >= 2)
					dp[i] = dp[i - 2] + 2;
				else
					dp[i] = 2;
			}
			else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
				if (i - dp[i - 1] >= 2)
					dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
				else
					dp[i] = dp[i - 1] + 2;
			}
			maxAns = max(maxAns, dp[i]);
		}
	}
	return maxAns;
}

int main() {
	

	return 0;
}
