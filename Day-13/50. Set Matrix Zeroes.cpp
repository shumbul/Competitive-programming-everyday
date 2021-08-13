// Link - https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3888/
// Author - Shumbul Arifa

class Solution {
	long long int inf = 1e15;
public:
	void setZeroes(vector<vector<int>>& mat) {
		// solving in 2 traversals using O(1) extra space
		int n = mat.size(), m = mat[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 0) {
					mat[i][j] = inf;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == (int)inf) {
					for (int k = 0; k < m; k++) {
						if (!(k != j && mat[i][k] == (int)inf))
							mat[i][k] = 0;
					}
					for (int k = 0; k < n; k++) {
						if (!(k != i && mat[k][j] == (int)inf))
							mat[k][j] = 0;
					}
				}
			}
		}
	}
};