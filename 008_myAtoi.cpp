//8. 字符串转换整数(atoi)
//
//请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C / C++ 中的 atoi 函数）。
//
//函数 myAtoi(string s) 的算法如下：
//
//读入字符串并丢弃无用的前导空格
//检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
//读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
//将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
//如果整数数超过 32 位有符号整数范围[−231, 231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
//返回整数作为最终结果。
//
//注意：
//
//本题中的空白字符只包括空格字符 ' ' 。
//除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。

//Tips:
//字符串处理的题目往往涉及复杂的流程以及条件情况，如果直接上手写程序，一不小心就会写出极其臃肿的代码。
//因此，为了有条理地分析每个输入字符的处理方法，
//我们可以使用确定有限状态机(deterministic finite automaton, DFA)
//
//程序在每个时刻有一个状态 s，每次从序列中输入一个字符 c，并根据字符 c 转移到下一个状态 s'。
//这样，我们只需要建立一个覆盖所有情况的从 s 与 c 映射到 s' 的表格即可解决题目中的问题。

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class FSM {
	//用表格表示这个DFA
	//           ' '     +/-     number     other
	//start      start   signed  in_number  end
	//signed     end     end     in_number  end
	//in_number  end     end     in_number  end
	//end        end     end     end        end
	unordered_map<string, vector<string>> stateTable = {
		{"start", {"start", "signed", "inNumber", "end"}},
		{"signed", {"end", "end", "inNumber", "end"}},
		{"inNumber", {"end", "end", "inNumber", "end"}},
		{"end", {"end", "end", "end", "end"}}
	};

	int nextState(char c) {
		if (c == ' ')
			return 0;
		if (c == '+' || c == '-')
			return 1;
		if (c >= '0' && c <= '9')
			return 2;
		return 3;
	}

	string state = "start";

public:
	bool isPositive = true;
	long long ans = 0;

	void get(char c) {
		state = stateTable[state][nextState(c)];
		if (state == "inNumber") {
			ans = ans * 10 + c - '0';
			if (isPositive)
				ans = min(ans, (long long)INT_MAX);
			else
				ans = -max(-ans, (long long)INT_MIN);
		}
		else if (state == "signed" && c == '-') {
			isPositive = false;
		}
	}
};

int myAtoi(string s) {
	FSM fsm;
	for (auto c : s)
		fsm.get(c);
	return fsm.isPositive ? fsm.ans : -fsm.ans;
}

int main() {
	

	return 0;
}
