#include <iostream>
#include <vector>
using namespace std;

//75. 颜色分类
//
//给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
//此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

//Tips:
//荷兰国旗问题
//双指针法
//使用指针 p0​ 来交换 0，p2 来交换 2。此时，p0 的初始值仍然为 0，而 p2 的初始值为 n - 1。
//在遍历的过程中，我们需要找出所有的 0 交换至数组的头部，并且找出所有的 2 交换至数组的尾部。
//
//  如果找到了 0，将其与 nums[p0] 进行交换，并将 p0 向后移动一个位置；
//  如果找到了 2，不断地将其与 nums[p2] 进行交换，直到新的 nums[i] 不为 2
//  如果遍历到的位置超过了 p2 ，那么就可以直接停止遍历了。

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int p0 = 0, p2 = n - 1;
    for (int i = 0; i <= p2; ++i) {
        while (i <= p2 && nums[i] == 2) {
            swap(nums[i], nums[p2]);
            --p2;
        }
        if (nums[i] == 0) {
            swap(nums[i], nums[p0]);
            ++p0;
        }
    }
}

int main() {
    

	return 0;
}
