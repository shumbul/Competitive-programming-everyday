// Link - https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
// Author - Shumbul Arifa

class Solution {
public:
	bool isPrefixString(string S, vector<string>& words) {
		int k = 0, n = S.length();
		for (auto s : words) {
			for (auto c : s) {
				if (k == n || c != S[k++])
					return false;
			}
			if (k == n)
				return true;
		}
		return k == n;
	}
};