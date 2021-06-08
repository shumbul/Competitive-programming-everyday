// Link - https://leetcode.com/problems/majority-element/
// Author - Shumbul Arifa

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int n = s.length(), m = t.length();
		if (n > m)
			return 0;
		int i, j;
		for (i = 0, j = 0; i < n, j < m;) {
			if (s[i] == t[j]) {
				i++, j++;
			}
			else
				j++;
		}
		if (i == n)
			return 1;
		return 0;
	}
};