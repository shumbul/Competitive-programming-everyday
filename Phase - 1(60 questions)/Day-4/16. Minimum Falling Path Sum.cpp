// Link - https://leetcode.com/problems/minimum-falling-path-sum/
// Author - Shumbul Arifa

#include<bits/stdc++.h>
class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int inf = 100001;
		int n = matrix.size();
		int m = matrix[0].size();
		if (n == 1)
			return matrix[0][0];
		// vector<vector<int>> dp(n,vector<int>(m));
		int dp[n][m];
		for (int i = 0; i < m; i++) {
			dp[n - 1][i] = matrix[n - 1][i];
		}
		int mini = inf;
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {

				dp[i][j] = dp[i + 1][j];
				if (j - 1 >= 0)
					dp[i][j] = min(dp[i + 1][j - 1], dp[i][j]);
				if (j + 1 < n)
					dp[i][j] = min(dp[i + 1][j + 1], dp[i][j]);
				dp[i][j] += matrix[i][j];
				if (i == 0) {
					mini = min(mini, dp[i][j]);
				}

			}
		}
		return mini;

	}
};