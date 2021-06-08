// Link - https://leetcode.com/problems/search-a-2d-matrix/
// Author - Shumbul Arifa

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& mat, int target) {
		// step -1
		// traverse in the last column, and select min row value with val greater than target
		int row = 0;
		int n = mat.size(), m = mat[0].size();
		for (int i = 0; i < n; i++) {
			if (mat[i][m - 1] >= target) {
				row = i;
				break;
			}
		}
		auto v = mat[row];
		return binary_search(v.begin(), v.end(), target);
	}
};