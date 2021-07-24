// Link - https://leetcode.com/problems/sqrtx/
// Author - Shumbul Arifa

class Solution {
public:
	int mySqrt(int x) {
		long long int l, h, mid;
		l = 0, h = x / 2 + 1;
		int ans = -1;
		while (l <= h) {
			mid = (h - l) / 2 + l;
			if (mid * mid <= x) {
				ans = mid;
				l = mid + 1;
			}
			else {
				h = mid - 1;
			}
		}
		return ans;
	}
};