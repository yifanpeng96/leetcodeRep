//3. 无重复字符的最长子串

//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

//Tips:
//滑动窗口

#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
	if (s == "")
		return 0;

	unordered_map<char, int> um;
	int sz = s.size();
	int maxSub = 1;
	int left = 0;
	for (int i = 0; i != sz; ++i) {
		if (um.find(s[i]) == um.end()) {
			um.insert(pair<char, int>(s[i], i));
		}
		else {
			if (um[s[i]] < left) {
				um[s[i]] = i;
				continue;
			}
			if (i - left > maxSub)
				maxSub = i - left;
			left = um[s[i]] + 1;
			um[s[i]] = i;
		}
	}

	if (sz - left > maxSub)
		maxSub = sz - left;

	return maxSub;
}

int main() {


	return 0;
}
