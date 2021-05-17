// Link - https://leetcode.com/problems/factorial-trailing-zeroes/
// Author - Shumbul Arifa

class Solution {
public:
	int trailingZeroes(int n) {
		int t5 = 0;
		while (n > 0) {
			n /= 5;
			t5 += n;
		}
		return t5;
	}
};