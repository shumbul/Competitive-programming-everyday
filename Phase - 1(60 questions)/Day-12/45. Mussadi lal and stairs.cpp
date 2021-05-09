// Link - https://www.codechef.com/problems/JAM11
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

int dp[100002];

void fill() {
	int n = 100002;
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
	}
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fill();
	int t;	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}