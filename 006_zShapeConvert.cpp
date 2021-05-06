//6. Z字形变换
//
//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//
//比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

//Tips:
//二维数组

#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
	if (numRows == 1)
		return s;

	int sz = s.size();
	vector<vector<char>> zShape(numRows, vector<char>((sz / (2 * numRows - 2) + 1) * (numRows - 1), ' '));

	for (int i = 0; i != sz; ++i) {
		if (i % (2 * numRows - 2) < numRows)
			zShape[i % (2 * numRows - 2)][i / (2 * numRows - 2) * (numRows - 1)] = s[i];
		else {
			int diff = i % (2 * numRows - 2) - numRows;
			zShape[numRows - diff - 2][i / (2 * numRows - 2) * (numRows - 1) + diff + 1] = s[i];
		}
	}

	string ans = "";
	for (int i = 0; i != numRows; ++i) {
		for (char j : zShape[i]) {
			if (j != ' ')
				ans += j;
		}
	}
	return ans;
}

int main() {
	

	return 0;
}
