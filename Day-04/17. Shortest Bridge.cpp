// Link - https://leetcode.com/problems/shortest-bridge/
// Author - Shumbul Arifa

class Solution {
	vector<vector<int>> vis;
	int m, n;
	int i1 = -1, j1, i2 = -1, j2;
	void dfs(set<pair<int, int>> &st, int i, int j, vector<vector<int>>& grid) {
		vis[i][j] = 1;
		st.insert(make_pair(i, j));
		if (i < n - 1 && grid[i + 1][j] && !vis[i + 1][j])
			dfs(st, i + 1, j, grid);
		if (j < m - 1 && grid[i][j + 1] && !vis[i][j + 1])
			dfs(st, i, j + 1, grid);
		if (i > 0 && grid[i - 1][j] && !vis[i - 1][j])
			dfs(st, i - 1, j, grid);
		if (j > 0 && grid[i][j - 1] && !vis[i][j - 1])
			dfs(st, i, j - 1, grid);
	}
public:
	int shortestBridge(vector<vector<int>>& grid) {
		n = grid.size();
		m = grid[0].size();
		vis.resize(n, vector<int> (m, 0));
		set<pair<int, int>> st, st1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1 && !vis[i][j]) {
					dfs(st, i, j, grid);
					cout << "now\n";
					// for(auto a:st){
					//     cout<<a.first<<" "<<a.second<<" <- inside\n";
					// }
					if (st1.empty()) {
						st1 = st;
					}
					if (i1 == -1)
						st.clear();
					if (i1 == -1)
						i1 = i, j1 = j;
					else if (i2 == -1)
						i2 = i, j2 = j;
				}
			}
		}
		// assert(st1!=st);
out:
		int ans = INT_MAX;
		for (auto a : st) {
			for (auto b : st1) {
				if (a != b) {
					// cout<<a.first<<" "<<a.second<<" <- a\n";
					// cout<<b.first<<" "<<b.second<<" <- b\n";
					ans = min(abs(a.first - b.first) + abs(a.second - b.second) - 1, ans);
				}
			}
		}
		return ans;
	}
};