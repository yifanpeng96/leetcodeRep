//67. 二进制求和
//
//给你两个二进制字符串，返回它们的和（用二进制表示）。
//
//输入为 非空 字符串且只包含数字 1 和 0。

#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
	a.size() > b.size() ? b = string(a.size() - b.size(), '0') + b : a = string(b.size() - a.size(), '0') + a;
	int sz = a.size();
	int carry = 0; //进位

	for (int i = sz - 1; i >= 0; --i) {
		if (a[i] == '0' && b[i] == '0' && carry) {
			a[i] = '1';
			--carry;
		}
		else if (a[i] == '1' && b[i] == '1' && carry == 0) {
			a[i] = '0';
			++carry;
		}
		else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
			if (carry)
				a[i] = '0';
			else
				a[i] = '1';
		}
	}

	if (carry)
		a.insert(a.begin(), '1');
	
	return a;
}

int main() {
	

	return 0;
}
