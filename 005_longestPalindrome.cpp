//5. 最长回文子串
//
//给你一个字符串 s，找到 s 中最长的回文子串。

//Tips:
//vector形式构建二元数组 m x n, 定义式为 vector<vector<int>> dp(m, vector<int>(n, 0));

#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
	int sz = s.size();
	if (sz < 2)
		return s;

	vector<vector<bool>> dp(sz, vector<bool>(sz, 0));
	//初始化, 所有长度为1的子串都为回文串
	for (int i = 0; i != sz; ++i)
		dp[i][i] = 1;
	
	int maxSubLeft = 0;
	int maxSubLength = 1;//保证形如"ab"的字符串可输出首字符

	//子串长度从小到大, 这样才能保证dp的正确性, 因此第一个循环为length, 第二个循环才为left
	for (int length = 2; length != sz + 1; ++length) {
		for (int left = 0; left != sz; ++left) {
			int right = left + length - 1;
			//确保边界不溢出
			if (right >= sz)
				break;

			if (s[left] == s[right] && length < 4)
				dp[left][right] = 1;
			else if (s[left] == s[right] && length >= 4) {
				dp[left][right] = dp[left + 1][right - 1];
			}

			if (dp[left][right] == 1 && length > maxSubLength) {
				maxSubLength = length;
				maxSubLeft = left;
			}
		}
	}
	return s.substr(maxSubLeft, maxSubLength);
}

int main() {
	

	return 0;
}
