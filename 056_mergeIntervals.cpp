//56. 合并区间
//
//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
//
//请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

//Tips:
// sort(intervals.begin(), intervals.end()) 可以直接按区间左端点排序

#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	list<vector<int>> ans;
	ans.push_back(intervals[0]);
	int sz = intervals.size();
	for (int i = 1; i != sz; ++i) {
		int left = intervals[i][0];
		int right = intervals[i][1];

		vector<list<vector<int>>::iterator> needBeOverlapped;
		for (auto it = ans.begin(); it != ans.end(); ++it) {
			if (((*it)[0] <= right && (*it)[1] >= left) || ((*it)[1] >= left && (*it)[0] <= right)) {
				(*it)[0] = min((*it)[0], left);
				(*it)[1] = max((*it)[1], right);
				left = (*it)[0];
				right = (*it)[1];
				needBeOverlapped.push_back(it);
			}
		}
		if (needBeOverlapped.empty())
			ans.push_back(intervals[i]);
		else {
			for (int j = 0; j != needBeOverlapped.size() - 1; ++j)
				ans.erase(needBeOverlapped[j]);
		}
	}
	vector<vector<int>> v_ans;
	for (auto v : ans)
		v_ans.push_back(v);
	return v_ans;
}

int main() {
	

	return 0;
}
