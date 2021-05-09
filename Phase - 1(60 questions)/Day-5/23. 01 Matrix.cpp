// Link - https://leetcode.com/problems/01-matrix/
// Author - Shumbul Arifa

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		vector<vector<int>> ans = matrix;
		// memset(ans, INT_MAX, sizeof ans);
		// fill zeroes
		int r = matrix.size(), c = matrix[0].size();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				if (matrix[i][j] != 0)
					ans[i][j] = 1e8 + 7;
				else
					ans[i][j] = 0;
		}
		// down, up, left, right
		for (int i = 1; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
			}
		}

		for (int i = r - 2; i >= 0; i--) {
			for (int j = 0; j < c; j++) {
				ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
			}
		}

		for (int i = 1; i < c; i++) {
			for (int j = 0; j < r; j++) {
				ans[j][i] = min(ans[j][i], ans[j][i - 1] + 1);
			}
		}

		for (int i = c - 2; i >= 0; i--) {
			for (int j = 0; j < r; j++) {
				ans[j][i] = min(ans[j][i], ans[j][i + 1] + 1);
			}
		}
		return ans;
	}
};