// Link - https://leetcode.com/problems/flipping-an-image/
// Author - Shumbul Arifa

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (m + 1) / 2; j++) {
				swap(mat[i][j], mat[i][m - j - 1]);
				mat[i][j] = !mat[i][j];
				if (j != m - j - 1)
					mat[i][m - j - 1] = !mat[i][m - j - 1];
			}
		}
		return mat;
	}
};