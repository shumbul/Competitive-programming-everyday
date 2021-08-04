// Link - https://codeforces.com/problemset/problem/118/D
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e8;

int N1, N2, K1, K2;
int dp[101][101][11][11];

int solve(int n1, int n2, int k1, int k2) {
	if (n1 + n2 == 0)
		return 1;
	// cout << n1 << " " << n2 << " " << k1 << " " << k2 << "\n";
	if (dp[n1][n2][k1][k2] != -1) {
		// cout << dp[n1][n2][k1][k2] << " k\n";
		return dp[n1][n2][k1][k2];
	}
	int x = 0, y = 0;
	if (n1 > 0 && k1 < K1)
		x = solve(n1 - 1, n2, k1 + 1, 0);
	if (n2 > 0 && k2 < K2)
		y = solve(n1, n2 - 1, 0, k2 + 1);
	// cout << "x y : " << x << " " << y << "\n";
	return dp[n1][n2][k1][k2] = (x + y) % mod;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> N1 >> N2 >> K1 >> K2;
	for0(i, N1 + 1)
	for0(j, N2 + 1)
	for0(k1, K1 + 1)
	for0(k2, K2 + 1)
	dp[i][j][k1][k2] = -1;
	cout << solve(N1, N2, 0, 0);

	return 0;
}