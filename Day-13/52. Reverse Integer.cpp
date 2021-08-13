// Link - https://leetcode.com/problems/reverse-integer/
// Author - Shumbul Arifa

class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		// stack like logic
		while (x != 0) {
			int top = x % 10;
			x /= 10; // pop
			// checking overflow
			if (rev > INT_MAX / 10 || rev == INT_MAX && top > 7)
				return 0;
			if (rev < INT_MIN / 10 || rev == INT_MIN && top < -8)
				return 0;
			rev = rev * 10 + top;
		}
		return rev;
	}
};