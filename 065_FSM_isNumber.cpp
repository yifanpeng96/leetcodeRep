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
//有限状态机, 各状态为:
//0. 初始状态
//1. 符号位
//2. 整数部分
//3. 左侧有整数的小数点
//4. 左侧无整数的小数点
//5. 小数部分
//6. 字符e
//7. 指数部分的符号位
//8. 指数部分的整数部分
//
//处理转移失败的情况时，我们可以创建一个特殊的拒绝状态。如果当前状态下没有对应读入字符的「转移规则」，
//我们就转移到这个特殊的拒绝状态。一旦自动机转移到这个特殊状态，我们就可以立即判定该字符串不「被接受」。

#include <iostream>
#include <unordered_map>
using namespace std;

-------------- 参考答案 ----------------------------------------------------------------------------------
 enum State {
	STATE_INITIAL,            //初始状态
	STATE_INT_SIGN,           //符号位
	STATE_INTEGER,            //整数部分
	STATE_POINT,              //左侧有整数的小数点
	STATE_POINT_WITHOUT_INT,  //左侧无整数的小数点
	STATE_FRACTION,           //小数部分
	STATE_EXP,                //字符e/E
	STATE_EXP_SIGN,           //指数符号
	STATE_EXP_NUMBER          //指数数字(整数)
};

enum CharType {
	CHAR_NUMBER,
	CHAR_EXP,
	CHAR_POINT,
	CHAR_SIGN,
	CHAR_ILLEGAL
};

CharType toCharType(char ch) {
	if (ch >= '0' && ch <= '9')
		return CHAR_NUMBER;
	if (ch == 'e' || ch == 'E')
		return CHAR_EXP;
	if (ch == '.')
		return CHAR_POINT;
	if (ch == '+' || ch == '-')
		return CHAR_SIGN;
	return CHAR_ILLEGAL;
}

bool isNumber(string s) {
	unordered_map<State, unordered_map<CharType, State>> transfer{
		{
			//初始状态只能为 0~9 or dot or +/-
			STATE_INITIAL, {
				{CHAR_NUMBER, STATE_INTEGER},
				{CHAR_POINT, STATE_POINT_WITHOUT_INT},
				{CHAR_SIGN, STATE_INT_SIGN}
			}
		},
		{
			//符号位后只能为 0~9 or dot
			STATE_INT_SIGN, {
				{CHAR_NUMBER, STATE_INTEGER},
				{CHAR_POINT, STATE_POINT_WITHOUT_INT}
			}
	    },
		{
			//整数部分后只能为 0~9 or e/E or dot
			STATE_INTEGER, {
				{CHAR_NUMBER, STATE_INTEGER},
				{CHAR_EXP, STATE_EXP},
				{CHAR_POINT, STATE_POINT}
			}
		},
		{
			//左侧有整数的小数点后只能为 0~9 or e/E
			STATE_POINT, {
				{CHAR_NUMBER, STATE_FRACTION},
				{CHAR_EXP, STATE_EXP}
			}
		}, 
		{
			//左侧无整数的小数点后只能为 0~9
			STATE_POINT_WITHOUT_INT, {
				{CHAR_NUMBER, STATE_FRACTION}
			}
		},
		{
			//小数部分后只能为 0~9 or e/E
			STATE_FRACTION, {
				{CHAR_NUMBER, STATE_FRACTION},
				{CHAR_EXP, STATE_EXP}
			}
		}, 
		{
			// e/E 后只能为 0~9 or +/-
			STATE_EXP, {
				{CHAR_NUMBER, STATE_EXP_NUMBER},
				{CHAR_SIGN, STATE_EXP_SIGN}
			}
		}, 
		{
			//指数符号后只能为 0~9
			STATE_EXP_SIGN, {
				{CHAR_NUMBER, STATE_EXP_NUMBER}
			}
		}, 
		{
			//指数数字后只能为 0~9
			STATE_EXP_NUMBER, {
				{CHAR_NUMBER, STATE_EXP_NUMBER}
			}
		}
	};

	int sz = s.size();
	State state = STATE_INITIAL;

	for (int i = 0; i != sz; ++i) {
		CharType type = toCharType(s[i]);
		if (transfer[state].count(type))
			state = transfer[state][type];
		else
			return false;
	}

	//终止状态只能为 整数部分 or 左侧有整数的小数点 or 小数部分 or 指数数字(整数)
	return state == STATE_INTEGER || state == STATE_POINT || state == STATE_FRACTION || state == STATE_EXP_NUMBER;
}

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
