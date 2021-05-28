// Link - https://leetcode.com/problems/longest-palindromic-subsequence/
// Author - Shumbul Arifa

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.length(), dp[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = -1;

		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
		}
		for (int i = 0; i < n - 1; i++) {
			if (s[i] != s[i + 1])
				dp[i][i + 1] = 1;
			else
				dp[i][i + 1] = 2;
		}
		for (int d = 3; d <= n; d++) {
			for (int i = 0; i <= n - d; i++) {
				int j = i + d - 1;
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else
					dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
			}
		}
		// for(int i=0;i<n;i++){
		//     for(int j=0;j<n;j++)
		//         cout<<dp[i][j]<<" ";
		//     cout<<"\n";
		// }
		return dp[0][n - 1];
	}
};