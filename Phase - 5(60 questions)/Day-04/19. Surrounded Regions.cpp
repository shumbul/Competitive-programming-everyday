// Link - https://leetcode.com/problems/surrounded-regions/
// Author - Shumbul Arifa

class Solution {
	vector<vector<pair<int, int>>> all;
	int n, m;
	void dfs(int i, int j, set<pair<int, int>> &vis, vector<pair<int, int>> &comps, bool &count, vector<vector<char>>& board) {
		// cout<<i<<" "<<j<<"\n";
		if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
			count = 0;
			return;
		}
		vis.insert(make_pair(i, j));
		comps.push_back(make_pair(i, j));
		if (vis.find(make_pair(i + 1, j)) == vis.end() && board[i + 1][j] == 'O')
			dfs(i + 1, j, vis, comps, count, board);
		if (vis.find(make_pair(i - 1, j)) == vis.end() && board[i - 1][j] == 'O')
			dfs(i - 1, j, vis, comps, count, board);
		if (vis.find(make_pair(i, j + 1)) == vis.end() && board[i][j + 1] == 'O')
			dfs(i, j + 1, vis, comps, count, board);
		if (vis.find(make_pair(i, j - 1)) == vis.end() && board[i][j - 1] == 'O')
			dfs(i, j - 1, vis, comps, count, board);
	}
public:
	void solve(vector<vector<char>>& board) {
		n = board.size(), m = board[0].size();
		set<pair<int, int>> vis;
		all.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'O' && vis.find(make_pair(i, j)) == vis.end()) {
					bool count = 1;
					vector<pair<int, int>> comps;
					dfs(i, j, vis, comps, count, board);
					if (count) {
						all.push_back(comps);
					}
				}
			}
		}
		for (auto a : all) {
			for (auto b : a)
				board[b.first][b.second] = 'X';
		}
	}
};