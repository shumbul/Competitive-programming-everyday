// Link - https://leetcode.com/problems/spiral-matrix/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& A) {
		int i, k = 0, l = 0;
		int m = A.size(), n = A[0].size();
		vector<int> temp;
		while (k < m && l < n) {
			for (i = l; i < n; ++i) {
				temp.push_back(A[k][i]);
			}
			k++;
			for (i = k; i < m; ++i) {
				temp.push_back(A[i][n - 1]);
			}
			n--;
			if (k < m) {
				for (i = n - 1; i >= l; --i) {
					temp.push_back(A[m - 1][i]);
				}
				m--;
			}
			if (l < n) {
				for (i = m - 1; i >= k; --i) {
					temp.push_back(A[i][l]);
				}
				l++;
			}
		}
		return temp;
	}
};