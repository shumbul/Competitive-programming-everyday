// Link - https://leetcode.com/problems/rotting-oranges/
// Author - Shumbul Arifa

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		queue<pair<int, int>> q;
		int time = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2) {
					q.push(make_pair(i, j));
				}
			}
		}
		set<pair<int, int>> vis;
		bool ok = 0;
		while (!q.empty()) {
			int s = q.size();
			while (s--) {
				auto rot = q.front();
				q.pop();
				vis.insert(rot);
				int i = rot.first, j = rot.second;
				// cout<<i<<" "<<j<<"\n";
				if (i > 0 && grid[i - 1][j] == 1 && vis.find(make_pair(i - 1, j)) == vis.end()) {
					grid[i - 1][j] = 2;
					q.push(make_pair(i - 1, j));
					ok = 1;
				}
				if (i < n - 1 && grid[i + 1][j] == 1 && vis.find(make_pair(i + 1, j)) == vis.end()) {
					grid[i + 1][j] = 2;
					q.push(make_pair(i + 1, j));
					ok = 1;
				}
				if (j > 0 && grid[i][j - 1] == 1 && vis.find(make_pair(i, j - 1)) == vis.end()) {
					grid[i][j - 1] = 2;
					q.push(make_pair(i, j - 1));
					ok = 1;
				}
				if (j < m - 1 && grid[i][j + 1] == 1 && vis.find(make_pair(i, j + 1)) == vis.end()) {
					grid[i][j + 1] = 2;
					q.push(make_pair(i, j + 1));
					ok = 1;
				}
			}
			if (ok)
				time++;
			ok = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					// cout<<i<<" "<<j<<"\n";
					return -1;
				}
			}
		}
		return time;
	}
};

// OPTIMIZATION
// instead of "ok", keep a count of 1s instead, and return time inside while when the count is 0