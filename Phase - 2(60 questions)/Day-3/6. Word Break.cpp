// Link - https://leetcode.com/problems/word-break/submissions/
// Link - https://practice.geeksforgeeks.org/problems/word-break1352/1#
// Author - Shumbul Arifa

class Solution {
public:
	bool wordBreak(string s, vector<string>& wd) {
		if (find(wd.begin(), wd.end(), s) != wd.end())
			return true;
		int n = s.length();
		bool dp[n + 1];
		for (int i = 1; i <= n; i++)
			dp[i] = false;
		dp[0] = true;

		for (int l = 1; l <= n; l++) {
			for (int i = 0; i < l; i++) {
				string t = s.substr(i, l - i);
				if (dp[i] && (find(wd.begin(), wd.end(), t) != wd.end() || t == "")) {
					dp[l] = true;
					break;
				}
			}
		}

		return dp[n];
	}
};