//36. 有效的数独
//
//请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
//
//数字 1 - 9 在每一行只能出现一次。
//数字 1 - 9 在每一列只能出现一次。
//数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
//数独部分空格内已填入了数字，空白格用 '.' 表示。
//
//注意：
//
//一个有效的数独（部分已被填充）不一定是可解的。
//只需要根据以上规则，验证已经填入的数字是否有效即可。

//Tips:
//一次遍历, 三个数组, 用哈希表来排除

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
	vector<unordered_set<char>> columns(9, unordered_set<char>(9));
	vector<unordered_set<char>> squares(9, unordered_set<char>(9));

	for (int i = 0; i != 9; ++i) {
		vector<char> row = board[i];
		unordered_set<char> validity;
		for (int j = 0; j != 9; ++j) {
			if (row[j] == '.')
				continue;
			
			//每行只能出现一次
			if (validity.count(row[j]) == 0)
				validity.insert(row[j]);
			else
				return false;

			//每列只能出现一次
			if (columns[j].count(row[j]) == 0)
				columns[j].insert(row[j]);
			else
				return false;

			//每个九宫格只能出现一次
			if (squares[3 * (i / 3) + j / 3].count(row[j]) == 0)
				squares[3 * (i / 3) + j / 3].insert(row[j]);
			else
				return false;
		}
	}

	return true;
}

int main() {
	

	return 0;
}
