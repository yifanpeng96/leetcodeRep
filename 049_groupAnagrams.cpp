//49. 字母异位词分组
//
//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

//Tips:
//哈希表

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> ans;
	int sz = strs.size();
	unordered_map<string, int> table;

	for (int i = 0; i != sz; ++i) {
		string sortedStr = strs[i];
		sort(sortedStr.begin(), sortedStr.end());
		if (table.count(sortedStr))
			ans[table[sortedStr]].push_back(strs[i]);
		else {
			int n = ans.size();
			table.insert(pair<string, int>(sortedStr, n));
			ans.push_back({ strs[i] });
		}
	}
	return ans;
}

int main() {
	

	return 0;
}
