//45. 跳跃游戏 II
//
//给定一个非负整数数组，你最初位于数组的第一个位置。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//
//假设你总是可以到达数组的最后一个位置。

//Tips:
//贪心算法: 「贪心」地进行正向查找，每次找到可到达的最远位置，就可以在线性时间内得到最少的跳跃次数。

#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
	int sz = nums.size();
	int maxPos = 0; //单个元素最大跳跃的元素下标
	int end = 0; //单个元素能跳到的范围
	int step = 0; //跳跃次数

	//i != sz - 1 说明不访问最后一个元素，这是因为在访问最后一个元素之前，我们的边界一定大于等于最后一个位置，
	//否则就无法跳到最后一个位置了。如果访问最后一个元素，在边界正好为最后一个位置的情况下，
	//我们会增加一次「不必要的跳跃次数」，因此我们不必访问最后一个元素。
	for (int i = 0; i != sz - 1; ++i) {
		if (i <= maxPos) { //从上个元素跳跃一次所包含的元素
			maxPos = max(maxPos, i + nums[i]);
			if (i == end) { //上个元素的最远跳跃
				end = maxPos;
				++step;
			}
		}
	}
	return step;
}

int main() {
	

	return 0;
}
