// Link - https://binarysearch.com/problems/Collecting-Coins-Sequel
// Author - Shumbul Arifa

int ANS = 0;
void dfs(vector<vector<int>> mat, int r, int c, int pr, int pc, int &ans, set<pair<int, int>> &vis) {
	if (pr < 0 || pr >= r || pc < 0 || pc >= c || vis.find(make_pair(pr, pc)) != vis.end()) return;
	cout << pr << " " << pc << "\n";
	int val = mat[pr][pc];
	mat[pr][pc] = 0;
	ans += val;
	ANS = max(ans, ANS);
	vis.insert(make_pair(pr, pc));
	if (pr < r - 1 && mat[pr + 1][pc] && vis.find(make_pair(pr + 1, pc)) == vis.end()) {
		dfs(mat, r, c, pr + 1, pc, ans, vis);
	}
	if (pr > 0 && mat[pr - 1][pc] && vis.find(make_pair(pr - 1, pc)) == vis.end()) {
		dfs(mat, r, c, pr - 1, pc, ans, vis);
	}
	if (pc < c - 1 && mat[pr][pc + 1] && vis.find(make_pair(pr, pc + 1)) == vis.end()) {
		dfs(mat, r, c, pr, pc + 1, ans, vis);
	}
	if (pc > 0 && mat[pr][pc - 1] && vis.find(make_pair(pr, pc - 1)) == vis.end()) {
		dfs(mat, r, c, pr, pc - 1, ans, vis);
	}
	vis.erase(make_pair(pr, pc));
	mat[pr][pc] = val;
	ans -= val;
}
int solve(vector<vector<int>> &mat) {
	int r = mat.size(), c = mat[0].size();
	int ans = 0;
	ANS = 0;
	set<pair<int, int>> vis;
	dfs(mat, r, c, 0, 0, ans, vis);
	return ANS;
}