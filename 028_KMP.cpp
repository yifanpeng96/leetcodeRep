//28. 实现 strStr()
//
//实现 strStr() 函数。
//
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中
//找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  - 1 。
//
//说明：
//
//当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//
//对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及
//Java 的 indexOf() 定义相符。

//Tips:
//KMP算法是一个快速查找匹配串的算法，它的作用是如何快速在「原字符串」中找到「匹配字符串」。
//时间复杂度：O(m + n), 其中n 为原串的长度，m 为匹配串的长度。
//
//前缀：对于字符串 abcxxxxefg，我们称 abc 属于 abcxxxxefg 的某个前缀。
//后缀：对于字符串 abcxxxxefg，我们称 efg 属于 abcxxxxefg 的某个后缀。
//
//匹配串会检查之前已经匹配成功的部分中里是否存在相同的「前缀」和「后缀」。
//如果存在，则跳转到「前缀」的下一个位置继续往下匹配：

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int strStr(string s, string p) {
    int n = s.size(), m = p.size();
    if (m == 0) return 0;
    //设置哨兵
    s.insert(s.begin(), ' ');
    p.insert(p.begin(), ' ');
    vector<int> next(m + 1);
    //预处理next数组
    for (int i = 2, j = 0; i <= m; i++) {
        while (j and p[i] != p[j + 1]) j = next[j];
        if (p[i] == p[j + 1]) j++;
        next[i] = j;
    }
    //匹配过程
    for (int i = 1, j = 0; i <= n; i++) {
        while (j and s[i] != p[j + 1]) j = next[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) return i - m;
    }
    return -1;
}

int main() {
	

	return 0;
}
