//65. 有效数字
//
//有效数字（按顺序）可以分成以下几个部分：
//1. 一个 小数 或者 整数
//2. （可选）一个 'e' 或 'E' ，后面跟着一个 整数
//
//小数（按顺序）可以分成以下几个部分：
//1. （可选）一个符号字符（'+' 或 '-'）
//2. 下述格式之一：
//  2.1 至少一位数字，后面跟着一个点 '.'
//  2.2 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
//  2.3 一个点 '.' ，后面跟着至少一位数字
//
//整数（按顺序）可以分成以下几个部分：
//1. （可选）一个符号字符（'+' 或 '-'）
//2. 至少一位数字
//
//部分有效数字列举如下：
//["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
//
//部分无效数字列举如下：
//["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
//
//给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。

//Tips:
//

#include <iostream>
#include <vector>
using namespace std;

-------------- 参考答案 ----------------------------------------------------------------------------------
 
-------------- 自己写的 ----------------------------------------------------------------------------------
bool is0to9(char x) {
	if (x >= '0' && x <= '9')
		return true;
	else
		return false;
}

bool isEore(char x) {
	if (x == 'e' || x == 'E')
		return true;
	else
		return false;
}

bool isSymbol(char x) {
	if (x == '+' || x == '-')
		return true;
	else
		return false;
}

bool isDot(char x) {
	if (x == '.')
		return true;
	else
		return false;
}

int dotOnly0or1 = 0;

bool FSM(string s, int n) {
	//末位只能是 0~9 or dot
	if (n == s.size() - 1) {
		if (is0to9(s[n]) || (isDot(s[n]) && s.size() != 1 && dotOnly0or1 == 0 && is0to9(s[n - 1]))) // "."无效
			return true;
		else
			return false;
	}
	
	if (is0to9(s[n])) // 0~9 后面只能是 0~9 or e/E or dot
		return (is0to9(s[n + 1]) || isEore(s[n + 1]) || isDot(s[n + 1])) && FSM(s, n + 1);
	if (isDot(s[n])) { // dot 后面只能是 0~9 or e/E, 如果是e/E的话, dot 前面必须是 0~9
		++dotOnly0or1;
		if (dotOnly0or1 == 2) return false;

		return (is0to9(s[n + 1]) || (isEore(s[n + 1]) && n > 0 && is0to9(s[n - 1]))) && FSM(s, n + 1);
	}
	if (isSymbol(s[n])) // +/- 后面只能是 0~9 or dot
		return (is0to9(s[n + 1]) || isDot(s[n + 1])) && FSM(s, n + 1);
	if (isEore(s[n])) {// e/E 后面只能是 整数 or +/-
		if (n == 0) // e/E 不能在首位
			return false;

		if (isSymbol(s[n + 1])) { //若为 +/-, 跳一位
			if (n + 1 == s.size() - 1)
				return false;
			else
				++n;
		}

		for (int i = n + 1; i != s.size(); ++i) {
			if (!is0to9(s[i]))
				return false;
		}
		return true;
	}

	return false; //其他符号都无效
}

bool isNumber(string s) {
	if (s.size() == 0) return false;

	//有限状态机
	return FSM(s, 0);
}

int main() {
	
	
	return 0;
}
