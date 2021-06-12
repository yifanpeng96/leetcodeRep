//51. N 皇后
//
//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//
//每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//不能相互攻击的意思是 任何两个皇后都不能在同一行、同一列以及同一条斜线上。

//Tips:
//回溯法
//具体做法是：使用一个数组记录每行放置的皇后的列下标，依次在每一行放置一个皇后。
//每次新放置的皇后都不能和已经放置的皇后之间有攻击：即新放置的皇后不能和任何一个已经放置的皇后在同一列以及同一条斜线上，
//并更新数组中的当前行的皇后列下标。当 NN 个皇后都放置完毕，则找到一个可能的解。当找到一个可能的解之后，
//将数组转换成表示棋盘状态的列表，并将该棋盘状态的列表加入返回列表。
//
//依次在每一行放置一个皇后。为了判断一个位置所在的列和两条斜线上是否已经有皇后，使用三个集合
//columns、diagonals1 和 diagonals2 分别记录每一列以及两个方向的每条斜线上是否有皇后。
//
//左上到右下方向的斜线上的每个位置满足行下标与列下标之差相等
//右上到左下方向的斜线上的每个位置满足行下标与列下标之和相等

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//根据已经找到的一个solution生成符合题目要求的vector
vector<string> generateOneBoard(vector<int>& queens, int n) {
	vector<string> oneBoard;
	for (int i = 0; i != n; ++i) {
		string row = string(n, '.');
		row[queens[i]] = 'Q';
		oneBoard.push_back(row);
	}
	return oneBoard;
}

void backtrack(vector<vector<string>>& solutions, vector<int>& queens, int n, int row,
	unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2) {
	if (row == n) {
		vector<string> oneBoard = generateOneBoard(queens, n);
		solutions.push_back(oneBoard);
	}
	else {
		//在row行上遍历 0 ~ i 列
		for (int i = 0; i != n; ++i) {
			//列上已经有皇后了, 跳过该格
			if (columns.count(i))
				continue;
			//左上到右下方向的斜线上已经有皇后了, 跳过该格
			if (diagonals1.count(row - i))
				continue;
			//右上到左下方向的斜线上已经有皇后了, 跳过该格
			if (diagonals2.count(row + i))
				continue;

			//把皇后放在row行i列上
			queens[row] = i;
			//在3个集合中记录该位置
			columns.insert(i);
			diagonals1.insert(row - i);
			diagonals2.insert(row + i);

			//继续在 row + 1 行上放皇后
			backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);

			//撤回该皇后的位置
			queens[row] = -1;
			//撤回3个集合中记录的位置
			columns.erase(i);
			diagonals1.erase(row - i);
			diagonals2.erase(row + i);
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> solutions;
	vector<int> queens(n, -1);
	unordered_set<int> columns;
	unordered_set<int> diagonals1;
	unordered_set<int> diagonals2;

	backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
	return solutions;
}

int main() {
	

	return 0;
}
