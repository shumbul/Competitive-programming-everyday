// Link - https://leetcode.com/problems/is-subsequence/
// Author - Shumbul Arifa

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int l1 = s.length(), l2 = t.length();
		int i = 0, j = 0;
		while (i < s.length() && j < t.length()) {
			if (s[i] == t[j]) {
				i++, j++;
			}
			else {
				j++;
			}
		}
		return i == l1;
	}
};