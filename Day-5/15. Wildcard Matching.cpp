// Link - https://leetcode.com/problems/wildcard-matching/submissions/
// Author - Shumbul Arifa

class Solution {
public:
	bool isMatch(string a, string p) {
		// removing consecutive *'s from p to reduce time and space
		string tmp;
		int k = 0;
		for (char c : p) {
			if (c == '*' && k > 0 && tmp[k - 1] == '*') {
				continue;
			}
			tmp += c;
			k++;
		}
		p = tmp;
		int m = a.length(), n = p.length();
		bool mat[n + 1][m + 1];
		mat[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			if (p[i - 1] == '*')
				mat[i][0] = mat[i - 1][0];
			else
				mat[i][0] = 0;
		}
		for (int j = 1; j <= m; j++) {
			mat[0][j] = 0;
		}
		bool ans = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[j - 1] == p[i - 1] || p[i - 1] == '?')
					mat[i][j] = mat[i - 1][j - 1];
				else if (p[i - 1] == '*')
					mat[i][j] = mat[i - 1][j] || mat[i][j - 1];
				else
					mat[i][j] = 0;

				if (mat[i][j] == 1)
					ans = true;
			}
			if (ans == false && m > 0) {
				return ans;
			}
			ans = false;
		}
		return mat[n][m];
	}
};