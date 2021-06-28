//68. 文本左右对齐
//
//给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
//
//你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
//
//要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
//
//文本的最后一行应为左对齐，且单词之间不插入额外的空格。
//
//说明:
//  单词是指由非空格字符组成的字符序列。
//  每个单词的长度大于 0，小于等于 maxWidth。
//  输入单词数组 words 至少包含一个单词。

//Tips:
//1. 先取出一行能够容纳的单词，将这些单词根据规则填入一行
// 
//2. 计算出额外空格的数量 spaceCount，额外空格就是正常书写用不到的空格
//  2.1 由总长度算起
//  2.2 除去每个单词末尾必须的空格，为了统一处理可以在结尾虚拟加上一个长度
//  2.3 除去所有单词的长度
//
//3. 按照单词的间隙数量 wordCount - 1，对额外空格平均分布，简单来说就是商和余数的计算
//	对于每个词填充之后，需要填充的空格数量等于 spaceSuffix + spaceAvg + ((i - bg) < spaceExtra)
//	spaceSuffix 【单词尾部固定的空格】
//	spaceAvg 【额外空格的平均值，每个间隙都要填入 spaceAvg 个空格】
//	((i - bg) < spaceExtra) 【额外空格的余数，前 spaceExtra 个间隙需要多 1 个空格】
//
//4. 特殊处理
//  4.1 一行只有一个单词，单词左对齐，右侧填满空格
//  4.2 最后一行，所有单词左对齐，中间只有一个空格，最后一个单词右侧填满空格

//fill函数的作用是：将一个区间的元素都赋予val值。函数参数：fill(start_iterator, end_iterator, val);
//fill_n函数的作用是：从迭代器指向的元素开始，将指定数量的元素设置为给定的值。函数参数：fill_n(iterator, count, val);
//注意： 不能在没有元素的空容器上调用fill_n函数
//为了保证算法有足够的元素存储输出数据，可使用"插入迭代器" back_inserter()

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

string fillWords(vector<string>& words, int maxWidth, int beg, int end, bool lastLine = false) {
	int wordCount = end - beg + 1; //一行中单词的数量
	int spaceCount = maxWidth + 1 - wordCount; //除去每个单词尾部空格后的长度, +1是指最后一个单词的尾部空格	
	for (int i = beg; i <= end; ++i)
		spaceCount -= words[i].size(); //一行中空格数量

	int spaceSuffix = 1; //词尾空格
	int spaceAvg = (wordCount == 1) ? 1 : spaceCount / (wordCount - 1); //单词后补加空格的平均值
	int spaceExtra = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1); //空格余数

	string ans = "";
	for (int i = beg; i != end; ++i) {
		ans += words[i];
		if (lastLine) { //若是最后一行
			fill_n(back_inserter(ans), 1, ' ');
			continue;
		}
		//fill_n()每写入一个值，都会通过back_inserter生成的插入迭代器实现。效果相当于在ans上调用push_back
		fill_n(back_inserter(ans), spaceSuffix + spaceAvg + ((i - beg) < spaceExtra), ' ');
	}
	ans += words[end]; //加上最后一个单词
	fill_n(back_inserter(ans), maxWidth - ans.size(), ' '); // 补上这一行最后的空格

	return ans;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> ans;
	int count = 0;
	int beg = 0;

	for (int i = 0; i != words.size(); ++i) {
		count += words[i].size() + 1;

		//如果是最后一个单词, 或者加上下一个词就超过长度了, 即可凑成一行
		if (i == words.size() - 1 || count + words[i + 1].size() > maxWidth) {
			ans.push_back(fillWords(words, maxWidth, beg, i, i + 1 == words.size()));
			beg = i + 1;
			count = 0;
		}
	}

	return ans;
}

int main() {
	

	return 0;
}
