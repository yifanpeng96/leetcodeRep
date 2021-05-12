//22. 括号生成
//
//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateNextParenthesis(string subAns, vector<string>& ans, int n, int leftNum) {
	if (leftNum == 0) {
		subAns.append(2 * n - subAns.size(), ')');
		ans.push_back(subAns);
		return;
	}

	string tmp1 = subAns + '(';
	generateNextParenthesis(tmp1, ans, n, leftNum - 1); //加(
	
	int rightNum = 2 * n - subAns.size() - leftNum;
	if (rightNum > leftNum) {
		string tmp2 = subAns + ')';
		generateNextParenthesis(tmp2, ans, n, leftNum); //加)
	}
	return;
}

vector<string> generateParenthesis(int n) {
	if (n < 1) return {};

	vector<string> ans;
	generateNextParenthesis("", ans, n, n);
	return ans;
}

int main() {
	

	return 0;
}
