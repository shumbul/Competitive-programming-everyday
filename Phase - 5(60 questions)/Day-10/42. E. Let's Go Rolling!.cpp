// Link - https://codeforces.com/problemset/problem/38/E
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
const int INF = 1e15;

pair<int, int> ar[3001];
int n;
int dp[3001][3001];

int getAns(int pos, int prev) {
	if (pos > n)
		return 0;
	if (dp[pos][prev] != -INF)
		return dp[pos][prev];
	// cout << pos << " " << ar[pos].first << " " << ar[pos].second << "\n";
	int incl = ar[pos].second + getAns(pos + 1, pos);
	int excl = abs(ar[pos].first - ar[prev].first) + getAns(pos + 1, prev);
	return dp[pos][prev] = min(incl, excl);
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for1(i, n)
	cin >> ar[i].first >> ar[i].second;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = -INF;	// -1 can also be a valid value in this problem
	sort(ar + 1, ar + n + 1);
	cout << ar[1].second + getAns(2, 1);

	return 0;
}