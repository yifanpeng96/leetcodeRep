//54. 螺旋矩阵
//
//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

//Tips:
//设定优先级

#include <iostream>
#include <vector>
using namespace std;

//优先级为 右 → 下 → 左 → 上
pair<int, int> neighbor(vector<vector<bool>>& occupied, int m, int n, pair<int, int> coord) {
	int i = coord.first;
	int j = coord.second;

	//在最左列总是向上
	if (i != 0 && (j == 0 || occupied[i][j - 1]) && !occupied[i - 1][j]) {
		occupied[i - 1][j] = true;
		return { i - 1, j };
	}
	else if (j + 1 < n && !occupied[i][j + 1]) {
		occupied[i][j + 1] = true;
		return { i, j + 1 };
	}
	else if (i + 1 < m && !occupied[i + 1][j]) {
		occupied[i + 1][j] = true;
		return { i + 1, j };
	}
	else if (j - 1 >= 0 && !occupied[i][j - 1]) {
		occupied[i][j - 1] = true;
		return { i, j - 1 };
	}
	else if (i - 1 >= 0 && !occupied[i - 1][j]) {
		occupied[i - 1][j] = true;
		return { i - 1, j };
	}
	return{ m, n };
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<bool>> occupied(m, vector<bool>(n, false));
	vector<int> ans;
	ans.push_back(matrix[0][0]);
	occupied[0][0] = true;
	pair<int, int> point = { 0, 0 };
	int timer = m * n - 1;

	while (timer) {
		point = neighbor(occupied, m, n, point);
		ans.push_back(matrix[point.first][point.second]);
		--timer;
	}
	return ans;
}

int main() {
	

	return 0;
}
