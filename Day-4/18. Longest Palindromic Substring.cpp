// Link - https://leetcode.com/problems/longest-palindromic-substring
// Author - Shumbul Arifa

class Solution {
public:
	string longestPalindrome(string s) {
		int l = s.length();
		if (l < 2)
			return s;
		bool dp[l + 1][l + 1];
		memset(dp, 0, sizeof dp);
		string ans = "";
		for (int i = 0; i <= l; i++) {
			dp[0][i] = 1;
			if (i)
				dp[1][i] = 1;
		}
		ans = s.substr(0, 1);
		for (int i = 2; i <= l; i++) {
			for (int j = i; j <= l; j++) {
				if (dp[i - 2][j - 1] && s[j - 1] == s[j - 1 - i + 1]) {
					dp[i][j] = 1;
					if (i > ans.length())
						ans = s.substr(j - i, i);
				}
			}
		}
		return ans;
	}
};