//29. 两数相除
//
//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
//
//返回被除数 dividend 除以除数 divisor 得到的商。
//
//整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

//Tips:
//注意考虑越界的情况: INT_MIN / -1
//把除数和被除数转换为负数来确保不会溢出
//倍增法:
//因为不可以使用乘法运算，因此可以采用加法实现倍增。具体思路比较简单：
//1.先都化成非负数，把符号位存下来为f1，f2
//2.创建一个列表1，存储除数的1，2，4，8……倍增，直到增加到大于被除数
//3.创建一个列表2，存储相比于给定的除数增加了多少倍（倍率）
//4.检索列表的最后一个元素和被除数的关系，如果大于被除数，直接把两个列表的最后一位都pop()了，否则的化被除数 -= 列表1的最后一个数，ans += 列表2的最后一个数，然后把两个列表最后一位pop()
//5.重复步骤4，直到被除数 < 除数
//6.返回ansf1f2，并判断是否在范围内

#include <iostream>
using namespace std;

int div_rec(long a, long b) {  // 似乎精髓和难点就在于下面这几句
    if (a < b) return 0;
    long count = 1;
    long tb = b; // 在后面的代码中不更新b
    while ((tb + tb) <= a) {
        count = count + count; // 最小解翻倍
        tb = tb + tb; // 当前测试的值也翻倍
    }
    return count + div_rec(a - tb, b);
}

int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1) {
        if (dividend > INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
        return INT_MAX;// 是最小的那个，那就返回最大的整数啦
    }
    long a = dividend;
    long b = divisor;
    int sign = 1;
    if ((a > 0 && b < 0) || (a < 0 && b>0)) {
        sign = -1;
    }
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    long res = div_rec(a, b);
    if (sign > 0)return res > INT_MAX ? INT_MAX : res;
    return -res;
}

int main() {
	

	return 0;
}
