//11. 盛最多水的容器
//
//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
//
//在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和(i, 0) 。
//
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
//说明：你不能倾斜容器。

//Tips:
//1. 双指针代表了什么？双指针代表的是 可以作为容器边界的所有位置的范围。
//2. 每次将 对应的数字较小的那个指针 往 另一个指针 的方向移动一个位置，
//   表示我们认为 这个指针不可能再作为容器的边界了。
//   实质就是在移动的过程中不断消去不可能成为最大值的状态。

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
	int left = 0, right = height.size() - 1;
	int max = 0;

	while (left < right) {
		int tmp = (right - left) * min(height[left], height[right]);
		if (tmp > max)
			max = tmp;
		height[left] <= height[right] ? ++left : --right;
	}
	return max;
}

int main() {
	

	return 0;
}
