// Link - https://codeforces.com/problemset/problem/474/D
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1000000007;

int N, K;
int dp[100007];
int pre[100007];

int solve(int n) {
	if (n == 0)
		return 1;
	if (dp[n] != -1)
		return dp[n];
	int ans = 0;
	ans += solve(n - 1), ans = ans % mod;
	if (n >= K)
		ans += solve(n - K) , ans = ans % mod;
	return dp[n] = ans;
}

void init() {
	for (int i = 1; i < 100001; i++) {
		pre[i] = pre[i - 1] + solve(i);
	}
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> N >> K;
	memset(dp, -1, sizeof dp);
	init();
	while (N--) {
		int a, b;	cin >> a >> b;
		cout << (pre[b] - pre[a - 1] + mod) % mod << "\n";
	}

	return 0;
}