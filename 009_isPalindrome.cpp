//9. 回文数
//
//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

//Tips:
//若不转为字符串的话, 可将数的后半部分反转然后与前半部分相比较

using namespace std;

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	if (x > 0 && !(x % 10))
		return false;

	int revertedNum = 0;
	while (x > revertedNum) {
		revertedNum = revertedNum * 10 + x % 10;
		x /= 10;
	}
	return x == revertedNum || x == revertedNum / 10;
}

int main() {


	return 0;
}
