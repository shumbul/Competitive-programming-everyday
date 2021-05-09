// Link - https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Author - Shumbul Arifa

class Solution {
	vector<vector<int>> dp;
	int dfs(vector<vector<int>>& mat, int m, int n, int i, int j, int prev) {
		if (i < 0 || j < 0 || i >= m || j >= n || mat[i][j] <= prev)
			return 0;
		if (dp[i][j] != 0)
			return dp[i][j];
		int left_ = dfs(mat, m, n, i - 1, j, mat[i][j]);
		int right_ = dfs(mat, m, n, i + 1, j, mat[i][j]);
		int up_ = dfs(mat, m, n, i, j + 1, mat[i][j]);
		int down_ = dfs(mat, m, n, i, j - 1, mat[i][j]);
		return dp[i][j] = max({left_, right_, up_, down_}) + 1;

	}
public:
	int longestIncreasingPath(vector<vector<int>>& mat) {
		if (mat.size() == 0)
			return 0;
		int m = mat.size(), n = mat[0].size();
		int res = 0;
		dp.resize(m, vector<int>(n));
		// memoization + dfs from every cell
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int d = dfs(mat, m, n, i, j, -1);
				res = max(res, d);
			}
		}
		return res;
	}
};