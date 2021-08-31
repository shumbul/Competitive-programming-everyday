// Link - https://leetcode.com/problems/guess-number-higher-or-lower/
// Author - Shumbul Arifa

class Solution {
public:
	int guessNumber(int n) {
		int i = guess(n);
		if (i == 0)
			return n;
		int l = 0, h = n, mid;
		while (l <= h) {
			mid = (h - l) / 2 + l;
			int g = guess(mid);
			if (g == 0)
				return mid;
			if (g == 1)
				l = mid + 1;
			else h = mid - 1;
		}
		return -1;
	}
};