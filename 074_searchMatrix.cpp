#include <iostream>
#include <vector>
using namespace std;

//74. 搜索二维矩阵
//
//编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
//
//每行中的整数从左到右按升序排列。
//每行的第一个整数大于前一行的最后一个整数。

//Tips:
//将矩阵每一行拼接在上一行的末尾, 得到一个升序数组. 二分查找

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size(), n = matrix[0].size();
	int left = 0, right = m * n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		int midNum = matrix[mid / n][mid % n];
		if (midNum < target)
			left = mid + 1;
		else if (midNum > target)
			right = mid - 1;
		else
			return true;
	}
	return false;
}

int main() {
    

	return 0;
}
