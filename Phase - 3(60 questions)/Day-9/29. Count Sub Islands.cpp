// Link - https://leetcode.com/contest/weekly-contest-246/problems/count-sub-islands/
// Author - Shumbul Arifa

class Solution {
	bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis, int i, int j, int m, int n) {
		if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0 || vis[i][j] == 1)
			return true;
		if (grid1[i][j] == 0) {
			return false;
		}
		vis[i][j] = 1;
		bool res = 1;
		res = dfs(grid1, grid2, vis, i, j + 1, m, n) && res;
		res = dfs(grid1, grid2, vis, i + 1, j, m, n) && res;
		res = dfs(grid1, grid2, vis, i, j - 1, m, n) && res;
		res = dfs(grid1, grid2, vis, i - 1, j, m, n) && res;
		return res;
	}
public:
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		int m = grid2.size(), n = grid2[0].size();
		vector<vector<int>> vis(m, vector<int> (n, 0));
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid2[i][j] == 1 && vis[i][j] == 0) {
					ans += dfs(grid1, grid2, vis, i, j, m, n);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cout << vis[i][j] << " ";
			cout << "\n";
		}
		return ans;
	}
};