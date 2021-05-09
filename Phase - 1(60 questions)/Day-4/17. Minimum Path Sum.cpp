// Link - https://leetcode.com/problems/minimum-path-sum/
// Author - Shumbul Arifa

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int inf = 10001;
		int n = grid.size(), m = grid[0].size();
		int dp[n][m + 2];
		for (int i = 0; i < n; i++) {
			dp[i][0] = inf;
			dp[i][m + 1] = inf;
		}
		dp[n - 1][m] = grid[n - 1][m - 1];

		for (int j = m - 1; j > 0; j--)
			dp[n - 1][j] = grid[n - 1][j - 1] + dp[n - 1][j + 1];

		for (int i = n - 2; i >= 0; i--) {
			for (int j = m; j > 0; j--) {
				dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j - 1];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m + 2; j++) {
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}
		return dp[0][1];
	}
};