// Link - https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
// Author - Shumbul Arifa

class Solution {
public:
	int countSubstrings(string s, string t) {
		int n1 = s.length(), n2 = t.length();
		int ans = 0;
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n2; j++) {
				int d = 0;
				int I = i, J = j;
				while (I < n1 && J < n2 && d < 2) {
					if (s[I] != t[J])
						d++;
					if (d == 1)
						ans++;
					I++, J++;
				}
			}
		}
		return ans;
	}
};