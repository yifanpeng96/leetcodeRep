//30. 串联所有单词的子串
//
//给定一个字符串 s 和一些长度相同的单词 words。
//找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
//
//注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

//Tips:
//1. 滑动窗口
//2. 哈希表
//3. 我们每次移动一个单词的长度，也就是 one_word 个字符，这样所有的移动被分成了one_word个类。
//   情况一：当子串完全匹配，移动到下一个子串的时候。
//   情况二：当判断过程中，出现不符合的单词。
//   情况三：判断过程中，出现的是符合的单词，但是次数超了。

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
	if (s.empty() || words.empty()) return {};

	//存放结果的数组
	vector<int> result;
	//words数组中单词的大小, 个数和总长度
	int one_word = words[0].size();//每个单词长度相同
	int word_num = words.size();
	int all_len = one_word * word_num;

	//建立单词->单词个数的映射
	unordered_map<string, int> table1;
	for (string word : words)
		++table1[word];

	for (int i = 0; i != one_word; ++i) {
		//建立滑动窗口, count表示匹配单词的个数
		int left = i, right = i, count = 0;

		unordered_map<string, int> table2;

		//开始滑动窗口
		while (right + one_word <= s.size()) {
			//从s中提取一个单词拷贝到word
			string word = s.substr(right, one_word);
			//窗口右边界右移一个单词的长度
			right += one_word;

			//若此单词不在words中, 表示匹配不成功, 重置单词个数、窗口边界以及table2
			if (table1.count(word) == 0) {
				count = 0;
				left = right;
				table2.clear();
			}
			//若此单词在words中, 表示匹配成功
			else {
				++table2[word];
				++count;

				//一个单词匹配多次，需要缩小窗口，也就是left右移
				while (table2[word] > table1[word]) {
					string t_word = s.substr(left, one_word);
					--count;
					--table2[t_word];
					left += one_word;
				}
				if (count == word_num)
					result.push_back(left);
			}
		}
	}
	return result;
}

int main() {
	

	return 0;
}

