//69. x 的平方根
//
//实现 int sqrt(int x) 函数。
//
//计算并返回 x 的平方根，其中 x 是非负整数。
//
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

//Tips:
//二分法
//注意两数相乘时可能会超过INT_MAX, 要用(long long)

//牛顿迭代法
//设函数 f(x) = x^2 - C . 求令 f(x) = 0 时的 x .

#include <iostream>
using namespace std;

int mySqrt_Bisection(int x) {
	int left = 0, right = x;
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if ((long long)mid * mid < x && (long long)(mid + 1) * (mid + 1) <= x)
			left = mid + 1;
		else if ((long long)mid * mid > x)
			right = mid - 1;
		else if ((long long)mid * mid <= x && (long long)(mid + 1) * (mid + 1) > x)
			return mid;
	}

	return left;
}

int mySqrt_Newton(int x) {
	double C = x;
	double x0 = x;

	while (1) {
		double xi = (x0 + C / x0) / 2;
		if (fabs(x0 - xi) < 1e-7) // abs()用于求整数的绝对值, fabs()用于求double/float的绝对值
			break;
		x0 = xi;
	}

	return (int)x0;
}

int main() {
	

	return 0;
}
