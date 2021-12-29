#include <iostream>
#include <string>
#include <vector>
using namespace std;

//72. 编辑距离
//
//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
//
//你可以对一个单词进行如下三种操作：
//
//插入一个字符
//删除一个字符
//替换一个字符

//Tips:
//c++中不允许使用变量作为数组的长度定义数组，必须为常量值，c++中所有的内存需求都是在程序执行前通过定义的常量来确定的。
//因此创建DP数组时不能直接 int DP[n + 1][m + 1]; //报错: 表达式必须含有常量值
//用 vector<vector<int>> DP(n + 1, vector<int>(m + 1)); 替代
// 
// 
//动态规划
//
//对单词 A 删除一个字符和对单词 B 插入一个字符是等价的
//对单词 B 删除一个字符和对单词 A 插入一个字符也是等价的
//对单词 A 替换一个字符和对单词 B 替换一个字符是等价的
//
//这样一来，本质不同的操作实际上只有三种：
//
//在单词 A 中插入一个字符；
//在单词 B 中插入一个字符；
//修改单词 A 的一个字符。
//
//用 D[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离。word1和word2的编辑距离为X，意味着word1最少经过X步，变成了word2
//
//D[i][j - 1] 为 A 的前 i 个字符和 B 的前 j - 1 个字符编辑距离的子问题。即对于 B 的第 j 个字符，
//我们在 A 的末尾添加了一个相同的字符，那么 D[i][j] 最小可以为 D[i][j - 1] + 1；
//
//D[i - 1][j] 为 A 的前 i - 1 个字符和 B 的前 j 个字符编辑距离的子问题。即对于 A 的第 i 个字符，
//我们在 B 的末尾添加了一个相同的字符，那么 D[i][j] 最小可以为 D[i - 1][j] + 1；
//
//D[i - 1][j - 1] 为 A 前 i - 1 个字符和 B 的前 j - 1 个字符编辑距离的子问题。即对于 B 的第 j 个字符，
//我们修改 A 的第 i 个字符使它们相同，那么 D[i][j] 最小可以为 D[i - 1][j - 1] + 1。
//特别地，如果 A 的第 i 个字符和 B 的第 j 个字符原本就相同，那么我们实际上不需要进行修改操作。
//在这种情况下，D[i][j] 最小可以为 D[i - 1][j - 1]。
//
//状态转移方程
//若 A 和 B 的最后一个字母相同：
//D[i][j] = min(D[i][j - 1] + 1, D[i - 1][j] + 1, D[i - 1][j - 1])
//        = 1 + min(D[i][j - 1], D[i - 1][j], D[i - 1][j - 1] - 1)
//
//若 A 和 B 的最后一个字母不同：
//D[i][j] = 1 + min(D[i][j - 1], D[i - 1][j], D[i - 1][j - 1])
//
//边界条件 D[i][0] = i, D[0][j] = j

int minDistance(string word1, string word2) {
	int n = word1.size(), m = word2.size();

	//有一个字符串为空
	if (n * m == 0) return n + m;

	//创建DP数组
	vector<vector<int>> DP(n + 1, vector<int>(m + 1));

	//初始化边界条件
	for (int i = 0; i != n + 1; ++i)
		DP[i][0] = i;
	for (int j = 0; j != m + 1; ++j)
		DP[0][j] = j;

	//计算所有DP值
	for (int i = 1; i != n + 1; ++i) {
		for (int j = 1; j != m + 1; ++j) {
			if (word1[i - 1] == word2[j - 1])
				DP[i][j] = 1 + min(DP[i][j - 1], min(DP[i - 1][j], DP[i - 1][j - 1] - 1));
			else
				DP[i][j] = 1 + min(DP[i][j - 1], min(DP[i - 1][j], DP[i - 1][j - 1]));
		}
	}

	return DP[n][m];
}

int main() {
    

	return 0;
}
