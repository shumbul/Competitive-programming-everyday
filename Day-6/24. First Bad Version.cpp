// Link - https://leetcode.com/problems/first-bad-version
// Author - Shumbul Arifa

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		// using bin search
		int l, h, mid;
		l = 1, h = n;
		while (l <= h) {
			if (l == h) {
				return l;
			}
			mid = (h - l) / 2 + l;
			if (isBadVersion(mid)) {
				h = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return -1;
	}
};