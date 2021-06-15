//55. 跳跃游戏
//
//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//判断你是否能够到达最后一个下标。

//Tips:
//贪心算法

#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
	int sz = nums.size();
	if (sz == 1) return true;

	int maxStep = 0;
	int i = 0;

	while (i < sz) {
		maxStep = max(maxStep, i + nums[i]);
		if (maxStep == i)
			return false;
		if (maxStep >= sz - 1)
			return true;
		++i;
	}
	return false;
}

int main() {
	

	return 0;
}
