// Link - https://cses.fi/problemset/task/1158/
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

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// knapsack based
	int n, x;	cin >> n >> x;
	vector<int> c(n, 0), p(n, 0);	// cost, pages
	for0(i, n)
	cin >> c[i];
	for0(i, n)
	cin >> p[i];

	vector<int> dp(x + 1, 0);
	for0(i, n) {
		for (int j = x; j >= c[i]; j--) {
			dp[j] = max(dp[j], dp[j - c[i]] + p[i]);
		}
	}

	cout << dp[x];

	return 0;
}