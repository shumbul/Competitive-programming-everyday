// Link - https://cses.fi/problemset/task/1633
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

	int n;	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	int l = 6;
	for1(i, n) {
		for (int j = 1; j <= min(i, l); j++) {
			dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}
	cout << dp[n];
	return 0;
}