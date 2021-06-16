//57. 插入区间
//
//给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
//
//在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	if (intervals.empty()) {
		intervals.push_back(newInterval);
		return intervals;
	}

	int left = newInterval[0];
	int right = newInterval[1];
	int sz = intervals.size();

	int i = 0;
	for (; i != sz; ++i) {
		if (intervals[i][1] >= left) {
			//无重叠
			if ((i == 0 && intervals[i][0] > right) || (i > 0 && intervals[i - 1][1] < left && intervals[i][0] > right)) {
				intervals.insert(intervals.begin() + i, newInterval);
				return intervals;
			}
			//有重叠
			else {
				intervals[i][0] = left = min(intervals[i][0], left);
				intervals[i][1] = right = max(intervals[i][1], right);
				break;
			}
		}
		//无重叠, 新区间在最末
		else if (i == sz - 1 && intervals[i][1] < left) {
			intervals.push_back(newInterval);
			return intervals;
		}
	}
	//有重叠的情况
	int stamp = i++;
	for (; i != sz; ++i) {
		if (intervals[i][0] <= intervals[stamp][1] && intervals[i][1] >= intervals[stamp][0]) {
			intervals[stamp][0] = min(intervals[i][0], intervals[stamp][0]);
			intervals[stamp][1] = max(intervals[i][1], intervals[stamp][1]);
		}
		else
			break;
	}
	//删去 stamp + 1 ~ i 的区间元素
	intervals.erase(intervals.begin() + stamp + 1, intervals.begin() + i);
	return intervals;
}

int main() {
	

	return 0;
}
