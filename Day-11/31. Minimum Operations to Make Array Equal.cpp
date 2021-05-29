// Link - https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// Author - Shumbul Arifa

class Solution {
public:
	int minOperations(int n) {
		int mid = n / 2;
		if (n % 2 == 0)
			return mid * mid;
		else
			return mid * (mid + 1);
	}
};