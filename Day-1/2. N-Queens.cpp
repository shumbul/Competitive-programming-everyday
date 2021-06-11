// Link - https://leetcode.com/problems/n-queens/
// Author - Shumbul Arifa

struct Pos {
	int row, col;
};

class Solution {
	vector<vector<string>> v;
public:
	vector<vector<string>> solveNQueens(int n) {
		struct Pos pos[n];
		bool ans = solveNQueens(n, 0, pos);
		if (ans) {
			return v;
		}
		return v;
	}
	bool solveNQueens(int n, int row, Pos pos[]) {
		if (n == row) {
			vector<string> thisv;
			string t, p;
			for (int j = 0; j < n; j++)
				p += ".";
			for (int i = 0; i < n; i++) {
				t = p;
				t[pos[i].col] = 'Q';
				thisv.push_back(t);
			}
			v.push_back(thisv);
			return false;
		}
		int col;
		for (col = 0; col < n; col++) {
			bool safe = 1;
			for (int queen = 0; queen < row; queen++) {
				if (pos[queen].col == col || pos[queen].row - pos[queen].col == row - col || pos[queen].row + pos[queen].col == row + col) {
					safe = 0;
					break;
				}
			}
			if (safe) {
				pos[row].row = row, pos[row].col = col;
				if (solveNQueens(n, row + 1, pos))
					return true;
			}
		}
		return false;
	}
};