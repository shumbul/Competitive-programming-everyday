// Link - https://leetcode.com/problems/rotate-image/
// Author - Shumbul Arifa

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		// Step - 1
		// flip across diagonal - 2
		int n = matrix.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; i + j + 1 < n; j++) {
				swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << matrix[i][j] << " ";
			cout << "\n";
		}
		// Step - 2
		// flip across horizontal middle row (row -> if exists )
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n; j++) {
				swap(matrix[i][j], matrix[n - i - 1][j]);
			}
		}
	}
};