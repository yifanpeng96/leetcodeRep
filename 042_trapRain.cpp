//42. 接雨水
//
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//枚举法
//水能达到的最高位置，等于两边最大高度的较小值减去当前高度的值。
int trap_enumeration(vector<int>& height) {
	int sz = height.size();
	if (sz < 3) return 0;

	vector<int> left_max(sz);
	vector<int> right_max(sz);

	//找到数组中从下标 i 到最左端最高的条形块高度 left_max
	left_max[0] = height[0];
	for (int i = 1; i != sz; ++i)
		left_max[i] = max(height[i], left_max[i - 1]);

	//找到数组中从下标 i 到最右端最高的条形块高度 right_max
	right_max[sz - 1] = height[sz - 1];
	for (int i = sz - 2; i >= 0; --i)
		right_max[i] = max(height[i], right_max[i + 1]);

	//水能达到的最高位置，等于两边最大高度的较小值减去当前高度的值
	int area = 0;
	for (int i = 1; i != sz - 1; ++i)
		area += min(left_max[i], right_max[i]) - height[i];

	return area;
}

//栈
//我们在遍历数组时维护一个栈。如果当前的条形块小于或等于栈顶的条形块，我们将条形块的索引入栈，
//意思是当前的条形块被栈中的前一个条形块界定。如果我们发现一个条形块长于栈顶，我们可以确定栈顶的条形块
//被当前条形块和栈的前一个条形块界定，因此我们可以弹出栈顶元素并且累加答案到 area
int trap_stack(vector<int>& height) {
	int area = 0, current = 0;
	int sz = height.size();
	stack<int> st;
	while (current < sz) {
		while (!st.empty() && height[current] > height[st.top()]) {
			int top = st.top();
			st.pop();
			if (st.empty())
				break;
			int distance = current - st.top() - 1;
			int bounded_height = min(height[current], height[st.top()]) - height[top];
			area += distance * bounded_height;
		}
		st.push(current);
		++current;
	}
	return area;
}

//双指针
//和 枚举法 相比，我们不从左和从右分开计算，我们想办法一次完成遍历。
int trap_twoPointers(vector<int>& height)
{
	int left = 0, right = height.size() - 1;
	int area = 0;
	int left_max = 0, right_max = 0;
	while (left < right) {
		if (height[left] < height[right]) {
			height[left] >= left_max ? (left_max = height[left]) : area += (left_max - height[left]);
			++left;
		}
		else {
			height[right] >= right_max ? (right_max = height[right]) : area += (right_max - height[right]);
			--right;
		}
	}
	return area;
}

int main() {
	

	return 0;
}
