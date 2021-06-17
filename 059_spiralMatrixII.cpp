//59. 螺旋矩阵 II
//
//给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };//右, 下, 左, 上
	vector<vector<int>>isOccupied = matrix; // 0 表示无元素, 1 表示已有元素
	matrix[0][0] = 1;
	isOccupied[0][0] = 1;
	int count = 2;
	int x = 0, y = 0;

	while (count <= n * n) {
		//特殊情况: 在每个正方形的最左边强制向上
		if ((y == 0 || isOccupied[x][y - 1]) && x > 0 && !isOccupied[x - 1][y]) {
			x = x + directions[3].first;
			y = y + directions[3].second;
			matrix[x][y] = count;
			isOccupied[x][y] = 1;
		}
		else {
			//选择一个方向
			for (int i = 0; i != 4; ++i) {
				//限定边界 0 ~ n - 1
				if (x + directions[i].first < n && x + directions[i].first >= 0 &&
					y + directions[i].second < n && y + directions[i].second >= 0) {
					//若无元素
					if (!isOccupied[x + directions[i].first][y + directions[i].second]) {
						x = x + directions[i].first;
						y = y + directions[i].second;
						matrix[x][y] = count;
						isOccupied[x][y] = 1;
						break;
					}
				}
			}
		}
		++count;
	}
	return matrix;
}

int main() {
	

	return 0;
}
