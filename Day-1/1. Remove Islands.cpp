// Link - https://www.youtube.com/watch?v=4tYoVx0QoN0
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

void dfs(vector < vector<int>> &mat, int i, int j, int n, int m) {
	// up
	if (i - 1 > 0 && mat[i - 1][j] == -1) {
		mat[i - 1][j] = 1;
		// cout << "changed up : " << i - 1 << " " << j << "\n";
		dfs(mat, i - 1, j, n, m);
	}
	// down
	if (i + 1 < n - 1 && mat[i + 1][j] == -1) {
		mat[i + 1][j] = 1;
		// cout << "changed down : " << i + 1 << " " << j << "\n";
		dfs(mat, i + 1, j, n, m);
	}
	// left
	if (j - 1 > 0 && mat[i][j - 1] == -1) {
		mat[i][j - 1] = 1;
		// cout << "changed left : " << i << " " << j - 1 << "\n";
		dfs(mat, i, j - 1, n, m);
	}
	// right
	if (j + 1 < m - 1 && mat[i][j + 1] == -1) {
		mat[i][j + 1] = 1;
		// cout << "changed right : " << i << " " << j + 1 << "\n";
		dfs(mat, i, j + 1, n, m);
	}
}

void solve(vector < vector<int>> &mat) {
	// 1. making all on border 1's -> -1
	int n = mat.size(), m = mat[0].size();
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++)
			if (mat[i][j] == 1) {
				mat[i][j] = -1;
			}
	}

	// 2. df on border 1's
	// row 0
	for (int i = 0; i < n; i++) {
		if (mat[i][0] == 1)
			dfs(mat, i, 0, n, m);
	}
	// row n-1
	for (int i = 0; i < n; i++) {
		if (mat[i][m - 1] == 1) {
			dfs(mat, i, m - 1, n, m);
		}
	}
	// col 0
	for (int i = 1; i < m - 1; i++) {
		if (mat[0][i] == 1)
			dfs(mat, 0, i, n, m);
	}
	// col m-1
	for (int i = 1; i < m - 1; i++) {
		if (mat[n - 1][i] == 1)
			dfs(mat, n - 1, i, n, m);
	}

	// 3. make all -1 -> 0
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++)
			if (mat[i][j] == -1) {
				mat[i][j] = 0;
			}
	}
}

signed main() {
	fast;
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	vector < vector<int>> mat = {
		{1, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 1, 1},
		{0, 0, 1, 0, 1, 0},
		{1, 1, 0, 0, 1, 0},
		{1, 0, 1, 1, 0, 0},
		{1, 0, 0, 0, 0, 1}
	};
	for (auto row : mat) {
		for (auto col : row) {
			cout << col << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	solve(mat);
	for (auto row : mat) {
		for (auto col : row) {
			cout << col << " ";
		}
		cout << "\n";
	}
	return 0;
}

/*
OUTPUT:

1 0 0 0 0 0
0 1 0 1 1 1
0 0 1 0 1 0
1 1 0 0 1 0
1 0 1 1 0 0
1 0 0 0 0 1

1 0 0 0 0 0
0 0 0 1 1 1
0 0 0 0 1 0
1 1 0 0 1 0
1 0 0 0 0 0
1 0 0 0 0 1

*/