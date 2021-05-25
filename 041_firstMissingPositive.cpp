//41. 缺失的第一个正数
//
//给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
//
//请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

//Tips:
//「真正」满足时间复杂度为 O(N) 且空间复杂度为 O(1) 的算法是不存在的，
//但是我们可以退而求其次：利用给定数组中的空间来存储一些状态。也就是说，如果题目给定的数组是不可修改的，
//那么就不存在满足时空复杂度要求的算法；但如果我们可以修改给定的数组，那么是存在满足要求的算法的。
//
//我们对数组进行遍历，对于遍历到的数 x，如果它在[1, N] 的范围内，那么就将数组中的第 x - 1 个位置（注意：数组下标从 0 开始）打上「标记」。
//在遍历结束之后，如果所有的位置都被打上了标记，那么答案是 N + 1 ，否则答案是最小的没有打上标记的位置加 1。
//
//由于题目要求我们只能使用常数级别的空间，而哈希表的大小与数组的长度是线性相关的，因此空间复杂度不符合题目要求。
//在这个限制下本题的思路有一个非正式的名称：原地哈希。

#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
	int sz = nums.size();
	for (int i = 0; i != sz; ++i) {
		while (nums[i] != i + 1) {
			//只排序 1 ~ sz范围内的正数, 且不重复
			if (nums[i] <= 0 || nums[i] > sz || nums[i] == nums[nums[i] - 1])
				break;
			//将 nums[i] 放置到数组的对应位置上, 如若nums[i] = 1, 就把该数与 nums[0] 交换位置
			int tmp = nums[i] - 1;
			nums[i] = nums[tmp];
			nums[tmp] = tmp + 1;
		}
	}
	for (int i = 0; i != sz; ++i) {
		if (nums[i] != i + 1)
			return i + 1;
	}
	return sz + 1;
}

int main() {
	

	return 0;
}
