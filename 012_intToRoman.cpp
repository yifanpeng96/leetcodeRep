//12. 整数转罗马数字
//
//罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
//
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X  + II 。 
// 27 写做  XXVII, 即为 XX  + V  + II 。
//
//通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
// 数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
// 同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//
//I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
//C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

//Tips:
//贪心算法, 尽可能优先使用较大数值对应的字符

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string intToRoman(int num) {
	if (num < 1 || num > 3999)
		return "";
	
	//int转roman
	unordered_map<int, string> table = { {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"},
		{100, "C"}, {500, "D"}, {1000, "M"}, {4, "IV"}, {9, "IX"}, {40, "XL"},
		{90, "XC"}, {400, "CD"}, {900, "CM"} };

	//把num拆分
	vector<int> nums;
	while (num) {
		if (num >= 1000) {
			num -= 1000;
			nums.push_back(1000);
		}
		else if (num >= 900) {
			num -= 900;
			nums.push_back(900);
		}
		else if (num >= 500) {
			num -= 500;
			nums.push_back(500);
		}
		else if (num >= 400) {
			num -= 400;
			nums.push_back(400);
		}
		else if (num >= 100) {
			num -= 100;
			nums.push_back(100);
		}
		else if (num >= 90) {
			num -= 90;
			nums.push_back(90);
		}
		else if (num >= 50) {
			num -= 50;
			nums.push_back(50);
		}
		else if (num >= 40) {
			num -= 40;
			nums.push_back(40);
		}
		else if (num >= 10) {
			num -= 10;
			nums.push_back(10);
		}
		else if (num >= 9) {
			num -= 9;
			nums.push_back(9);
		}
		else if (num >= 5) {
			num -= 5;
			nums.push_back(5);
		}
		else if (num >= 4) {
			num -= 4;
			nums.push_back(4);
		}
		else if (num >= 1) {
			num -= 1;
			nums.push_back(1);
		}
	}

	string ans = "";
	for (int c : nums)
		ans += table[c];
	
	return ans;
}

int main() {


	return 0;
}
