//17. 电话号码的字母组合
//
//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//数字到字母的映射与电话按键相同。注意 1 不对应任何字母。

//Tips:
//1. char转string的方法: char x; (1) string s(1, x); (2) s.push_back(x);
//                     (3) char xx[2] = {x, 0}; string s(xx); string可由char*初始化
//2. 当题目中出现 “所有组合” 等类似字眼时，我们第一感觉就要想到用回溯。(本题没想到, 先用了穷举法)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//穷举法
vector<string> letterCombinations(string digits) {
	if (digits == "") return {};
	
	unordered_map<char, string> table = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
		{'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
	
	vector<string> ans;
	for (int i = 0; i != table[digits[0]].size(); ++i)
		ans.push_back(string(1, table[digits[0]][i]));

	for (int i = 1; i != digits.size(); ++i) {
		vector<string> tmp;
		for (int j = 0; j != ans.size(); ++j) {
			for (int k = 0; k != table[digits[i]].size(); ++k)
				tmp.push_back(ans[j] + table[digits[i]][k]);
		}
		swap(tmp, ans);
	}
	return ans;
}

//回溯法
void backtrack(vector<string>& combinations, unordered_map<char, string>& table,
	string& digits, int index, string& combination) {
	if (index == digits.size())
		combinations.push_back(combination);
	else {
		string letters = table[digits[index]];

		for (auto letter : letters) {
			combination.push_back(letter);
			backtrack(combinations, table, digits, index + 1, combination);
			combination.pop_back();
		}
	}
}

vector<string> letterCombinations_backtrack(string digits) {
	if (digits == "") return {};

	unordered_map<char, string> table = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
		{'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
	vector<string> combinations;
	string combination = "";

	backtrack(combinations, table, digits, 0, combination);
	return combinations;
}

int main() {
	

	return 0;
}
