// Link - https://leetcode.com/problems/decode-ways
// Author - Shumbul Arifa

class Solution {
public:
	int numDecodings(string s) {
		// A char may be decoded alone or by pairing with the next char
		int n = s.length();
		if (n < 2)
			return n;
		vector<int> dp(n + 1, 0);
		dp[n] = 1;  // base case
		// to handle the case of avoiding a number starting with '0'
		// we traverse back
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '0')
				dp[i] = 0;
			else {
				dp[i] = dp[i + 1];
				// two digit
				if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) dp[i] += dp[i + 2];
			}
		}
		return dp[0];
	}
};