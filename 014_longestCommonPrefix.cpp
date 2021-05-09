//14. 最长公共前缀
//
//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (!strs.size()) {
        return "";
    }
    string prefix = strs[0];
    int sz = strs.size();
    for (int i = 1; i != sz; ++i) {
        prefix = CommonPrefix(prefix, strs[i]);
        if (!prefix.size())
            break;
    }
    return prefix;
}

string CommonPrefix(const string& str1, const string& str2) {
    int length = min(str1.size(), str2.size());
    int index = 0;
    while (index < length && str1[index] == str2[index])
        ++index;
    
    return str1.substr(0, index);
}

int main() {
	

	return 0;
}
