// Link - https://leetcode.com/problems/count-sorted-vowel-strings/
// Author - Shumbul Arifa

class Solution {
public:
	int countVowelStrings(int n) {
		int ans = 0;
		int dp[n + 1][6];
		for (int i = 0; i <= n; i++)   dp[i][0] = 0;
		for (int i = 0; i <= 5; i++)   dp[0][i] = 0;
		for (int i = 0; i <= 5; i++)   dp[1][i] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= 5; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				// cout<<dp[i][j]<<" ";
			}
			// cout<<"\n";
		}
		for (int i = 1; i <= 5; i++) {
			// cout<<dp[n][i]<<" ";
			ans += dp[n][i];
		}
		return ans;
	}
};