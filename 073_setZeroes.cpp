#include <iostream>
#include <vector>
using namespace std;

//73. 矩阵置零
//
//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

void setZeroes(vector<vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	//记录第一列是否原本存在0
	bool flag = false;
	//用第一行和第一列来标记该列/行是否存在0元素
	for (int i = 0; i != m; ++i) {
		if (matrix[i][0] == 0)
			flag = true;
		for (int j = 1; j != n; ++j) {
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
		}
	}

	//从最后一行开始倒序处理矩阵元素
	for (int i = m - 1; i >= 0; --i) {
		for (int j = 1; j != n; ++j) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
		if (flag)
			matrix[i][0] = 0;
	}
}

int main() {
    

	return 0;
}
