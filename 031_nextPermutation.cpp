//31. 下一个排列
//
//实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//
//如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//
//必须 原地 修改，只允许使用额外常数空间。

//Tips:
//1. 在尽可能靠右的低位进行交换，需要从后向前查找
//2. 将一个 尽可能小的「大数」 与前面的「小数」交换。比如 123465，
//   下一个排列应该把 5 和 4 交换而不是把 6 和 4 交换
//3. 将「大数」换到前面后，需要将「大数」后面的所有数重置为升序，升序排列就是最小的排列。
//   以 123465 为例：首先按照上一步，交换 5 和 4，得到 123564；
//   然后需要将 5 之后的数重置为升序，得到 123546。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int sz = nums.size();
	if (sz == 0 || sz == 1) return;
	
	int i = sz - 1;
	for (; i != 0; --i) {
		if (nums[i] > nums[i - 1]) {
			int j = sz - 1;
			for (; j > i; --j) {
				if (nums[j] > nums[i - 1]) {
					break;
				}
			}

			int tmp = nums[i - 1];
			nums[i - 1] = nums[j];
			nums[j] = tmp;

			vector<int>::iterator it = nums.begin() + i;
			sort(it, nums.end());
			return;
		}
	}

	sort(nums.begin(), nums.end());
	return;
}

int main() {
	

	return 0;
}
