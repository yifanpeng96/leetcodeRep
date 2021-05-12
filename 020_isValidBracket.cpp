//20. 有效的括号
//
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
//有效字符串需满足：
//
//1. 左括号必须用相同类型的右括号闭合。
//2. 左括号必须以正确的顺序闭合。

//Tips:
//map容器的初始化可用{ {...}, {...}, ... }

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
	if (s.empty()) return true;

	unordered_map<char, char> tras = { {'(', ')'}, {'[', ']'}, {'{', '}'} };
	stack<char> validity;

	int sz = s.size();
	for (int i = 0; i != sz; ++i) {
		if (validity.empty() || validity.top() != s[i])
			validity.push(tras[s[i]]);
		else
			validity.pop();
	}
	return validity.empty();
}

int main() {
	

	return 0;
}
