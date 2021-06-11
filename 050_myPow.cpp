//50. Pow(x, n)
//
//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。

//Tips:
//快速幂

#include <iostream>
using namespace std;

double quickMul(double x, long long N) {
    if (N == 0) {
        return 1.0;
    }
    double y = quickMul(x, N / 2);
    return N % 2 == 0 ? y * y : y * y * x;
}

double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
}

int main() {
	

	return 0;
}
