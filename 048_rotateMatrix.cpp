//48. 旋转图像
//
//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

//Tips:
//顺时针旋转 等价于 水平翻转 + 对角线翻转
//逆时针旋转 等价于 竖直翻转 + 对角线翻转

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	//水平翻转
	for (int i = 0; i != n / 2; ++i) {
		for (int j = 0; j != n; ++j)
			swap(matrix[i][j], matrix[n - i - 1][j]);
	}
	//对角线翻转
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != i; ++j)
			swap(matrix[i][j], matrix[j][i]);
	}
}

int main() {
	

	return 0;
}
