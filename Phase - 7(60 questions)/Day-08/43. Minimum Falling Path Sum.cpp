// Link - https://leetcode.com/problems/minimum-falling-path-sum/
// Author - Shumbul Arifa

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		int dp[n][m];
		int ans = 102;
		for (int j = 0; j < m; j++)    dp[n - 1][j] = mat[n - 1][j], ans = min(ans, dp[n - 1][j]);
		if (m == 1)
			return ans;
		ans = INT_MAX;
		for (int i = n - 2; i >= 0; --i) {
			for (int j = 0; j < m; ++j) {
				dp[i][j] = dp[i + 1][j];
				if (j - 1 >= 0 && dp[i + 1][j - 1] < dp[i][j])  dp[i][j] = dp[i + 1][j - 1];
				if (j + 1 < m && dp[i + 1][j + 1] < dp[i][j])  dp[i][j] = dp[i + 1][j + 1];
				dp[i][j] += mat[i][j];
				if (!i)
					ans = min(ans, dp[i][j]);
			}
		}
		return ans;
	}
};