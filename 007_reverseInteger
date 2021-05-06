//7. 整数反转
//
//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//
//如果反转后整数超过 32 位的有符号整数的范围 [−2^31, 2^31 − 1] ，就返回 0。
//
//假设环境不允许存储 64 位整数（有符号或无符号）。

//Tips:
//本题限制不能用long, INT_MAX = 2 147 483 647
//负数取余仍是负数, 如 -1 % 10 == -1
//考虑 INT_MIN <= 10 * ans + digit <= INT_MAX, 化简得 INT_MIN / 10 <= ans <= INT_MAX / 10

#include <algorithm>
using namespace std;

int reverse(int x) {
	int ans = 0;
	while (x != 0) {
		if (ans < INT_MIN / 10 || ans > INT_MAX / 10)
			return 0;

		int digit = x % 10;
		ans = ans * 10 + digit;
		x /= 10;
	}
	return ans;
}

int main() {
	

	return 0;
}
