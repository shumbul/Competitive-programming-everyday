// Link - https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Author - Shumbul Arifa

class Solution {
public:
	int countSquares(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();

		auto v = mat;

		for (int i = 1; i < n; i++)

			for (int j = 1; j < m; j++)

				if (v[i][j])

					v[i][j] = min(v[i - 1][j], min(v[i - 1][j - 1], v[i][j - 1])) + 1;

		int ans = 0;

		for (int i = 0; i < n; i++)

			for (int j = 0; j < m; j++)

				ans += v[i][j];

		return ans;
	}
};