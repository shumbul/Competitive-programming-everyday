// Link - https://leetcode.com/problems/number-of-provinces/
// Author - Shumbul Arifa

class Solution {
	int vis[10001];
	int comp = 0;
	void dfs(int i, vector<vector<int>>& mat) {
		vis[i] = 1;
		for (int j = 0; j < mat[0].size(); j++) {
			if (mat[i][j] && !vis[j])
				dfs(j, mat);
		}
	}
public:
	int findCircleNum(vector<vector<int>>& mat) {
		// components in matrix
		comp = 0;
		for (int i = 0; i < mat.size(); i++)
			vis[i] = 0;
		for (int i = 0; i < mat.size(); i++) {
			if (!vis[i])
				comp++, dfs(i, mat);
		}
		return comp;
	}
};