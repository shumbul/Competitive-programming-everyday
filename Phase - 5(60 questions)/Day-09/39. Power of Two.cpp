// Link - https://leetcode.com/problems/power-of-two/
// Author - Shumbul Arifa

class Solution {
public:
	bool isPowerOfTwo(int n) {
		// bit manipulation method
		// if no. of set bits = 1, return true, otherwise false
		if (n < 0) return false;
		int cnt = 0;
		while (n) {
			n = n & (n - 1);
			cnt++;
		}
		return cnt == 1;

	}
};