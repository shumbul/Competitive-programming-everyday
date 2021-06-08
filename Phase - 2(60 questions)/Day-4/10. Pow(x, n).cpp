// Link - https://leetcode.com/problems/powx-n/
// Author - Shumbul Arifa

class Solution {
public:
#define ll double
	double myPow(double a, int n) {
		if (a == 1 || a == -1 && n % 2 == 0)
			return 1.00000;
		if (a == -1 && n % 2)
			return -1.00000;
		if (n < 0) {
			if (n == -2147483648)
				return 0;
			a = 1.0 / (a * 1.0);
			n *= -1;
		}
		ll p = 1;
		while (n > 0) {
			if (n % 2) {
				p = p * a;
			}
			n >>= 1;
			a *= a;
		}
		return p;
	}
};