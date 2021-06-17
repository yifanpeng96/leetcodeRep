//58. 最后一个单词的长度
//
//给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。
//
//如果不存在最后一个单词，请返回 0 。
//
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
	int sz = s.size();
	if (sz == 0) return 0;

	//忽略s末尾的空格
	int i = sz - 1;
	for (; i >= 0; --i) {
		if (s[i] != ' ')
			break;
		else if (i == 0)
			return 0;
	}
	//最后一个单词的最后一位
	int end = i;
	//遍历单词直到遇到第一个空格
	for (; i >= 0; --i) {
		if (s[i] == ' ')
			break;
		else if (i == 0) {
			--i;
			break;
		}
	}
	//最后一个单词的第一位
	int start = ++i;
	return end - start + 1;
}

int main() {
	

	return 0;
}
