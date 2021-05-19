//36. 解数独
//
//编写一个程序，通过填充空格来解决数独问题。
//
//数独的解法需 遵循如下规则：
//
//数字 1 - 9 在每一行只能出现一次。
//数字 1 - 9 在每一列只能出现一次。
//数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
//数独部分空格内已填入了数字，空白格用 '.' 表示。

//Tips:
//1. 递归
//2. 在 C++11 之后，vector 容器中添加了新的方法：emplace_back() ，
//   和 push_back() 一样的是都是在容器末尾添加一个新的元素进去，不同的是 emplace_back() 
//   在效率上相比较于 push_back() 有了一定的提升，因为省去了拷贝构造过程。
//3.
//使用 line[i]， column[j]， block[x][y] 分别表示第 i 行，第 j 列，第 (x, y) 个九宫格中
//填写数字的情况。九宫格的范围为 0 ≤ x ≤ 2 以及 0 ≤ y ≤ 2。如line[2][3]=true 表示数字4在第2行出现过。
//具体地，第 i 行第 j 列的格子位于第([i / 3], [j / 3]) 个九宫格中，其中 [u] 表示对 u 向下取整。
//
//4. 算法:
//我们首先对整个数独数组进行遍历，当我们遍历到第 i 行第 j 列的位置：
//如果该位置是一个空白格，那么我们将其加入一个用来存储空白格位置的列表中，方便后续的递归操作；
//如果该位置是一个数字 x，那么我们需要将 line[i][x−1]， column[j][x−1] 以及 block[i / 3][j / 3][x−1] 均置为 true。
//
//当我们结束了遍历过程之后，就可以开始递归枚举。当递归到第 i 行第 j 列的位置时，我们枚举填入的数字 x。
//根据题目的要求，数字 x 不能和当前行、列、九宫格中已经填入的数字相同，因此 line[i][x−1]， column[j][x−1] 
//以及 block[⌊i / 3⌋][⌊j / 3⌋][x−1] 必须均为 false。

//当我们填入了数字 x 之后，我们要将上述的三个值都置为 true，并且继续对下一个空白格位置进行递归。
//在回溯到当前递归层时，我们还要将上述的三个值重新置为 false。

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool line[9][9], column[9][9], block[3][3][9];
bool valid = false;
vector<pair<int, int>> spaces;

void dfs(vector<vector<char>>& board, int pos) {
	if (pos == spaces.size()) {
		valid = true;
		return;
	}

	int i, j;
	pair<int, int>(i, j) = spaces[pos]; //本轮迭代能填几个数. spaces表示原数独中的空白位置
	for (int digit = 0; digit < 9 && !valid; ++digit) {
		//如果第 i 行，第 j 列的数字digit可以使用, 就填入board中, 再
		if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
			line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
			board[i][j] = digit + '0' + 1; //digit是从0~8, 而数独是1~9, 所以要+1
			dfs(board, pos + 1);
			//回溯到当前递归层时，还要将这三个值重新置为 false。
			line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
		}
	}
}

void solveSudoku(vector<vector<char>>& board) {
	for (int i = 0; i != 9; ++i) {
		for (int j = 0; j != 9; ++j) {
			if (board[i][j] == '.')
				spaces.emplace_back(i, j); //在容器末尾添加一个新的元素进去
			else {
				int digit = board[i][j] - '0' - 1;
				line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
			}
		}
	}
	dfs(board, 0);
}

int main() {
	

	return 0;
}
