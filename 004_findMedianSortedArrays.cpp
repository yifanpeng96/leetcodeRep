//4. 寻找两个正序数组的中位数
//
//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

//Tips:
//如何把时间复杂度降低到O(log(m+n))? 如果对时间复杂度的要求有log, 通常都需要用到二分查找

//主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
//这里的 "/" 表示整除
//nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
//nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
//取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
//这样 pivot 本身最大也只能是第 k-1 小的元素
//如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
//如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
//由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数

#include <vector>
using namespace std;

int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    int index1 = 0, index2 = 0;

    while (true) {
        // 边界情况
        if (index1 == m) {
            return nums2[index2 + k - 1];
        }
        if (index2 == n) {
            return nums1[index1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[index1], nums2[index2]);
        }

        // 正常情况
        int newIndex1 = min(index1 + k / 2 - 1, m - 1);
        int newIndex2 = min(index2 + k / 2 - 1, n - 1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if (pivot1 <= pivot2) {
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        }
        else {
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalLength = nums1.size() + nums2.size();
    if (totalLength % 2 == 1) {
        return getKthElement(nums1, nums2, (totalLength + 1) / 2);
    }
    else {
        return (getKthElement(nums1, nums2, totalLength / 2) + 
            getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    }
}

//如果不考虑时间复杂度的话，用 len 表示合并后数组的长度，如果是奇数，我们需要知道第 （len+1）/2 个数就可以了，如果遍历的话需要遍历 int(len/2 ) + 1 次。
//如果是偶数，我们需要知道第 len/2和 len/2+1 个数，也是需要遍历 len/2+1 次。所以遍历的话，奇数和偶数都是 len/2+1 次。

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int sz1 = nums1.size(), sz2 = nums2.size();
	int sz = sz1 + sz2;
	
	//用两个变量 left 和 right，right 保存当前循环的结果，在每次循环前将 right 的值赋给 left。
	//这样在最后一次循环的时候，left 将得到 right 的值，也就是上一次循环的结果，接下来 right 更新为最后一次的结果。
	int left = -1, right = -1;

	//用 aStart 和 bStart 分别表示当前指向 A 数组和 B 数组的位置
	int aStart = 0, bStart = 0;

	for (int i = 0; i <= sz / 2; ++i) {
		left = right;
		if (aStart < sz1 && (bStart >= sz2 || nums1[aStart] < nums2[bStart]))
			right = nums1[aStart++];
		else
			right = nums2[bStart++];
	}
	if (sz & 1)
		return right;
	else
		return (left + right) / 2.0;
}

int main() {
	

	return 0;
}
