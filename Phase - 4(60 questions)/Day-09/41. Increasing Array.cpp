// Link - https://cses.fi/problemset/task/1094
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
	vector<int> ar(n);
	for0(i, n)	cin >> ar[i];
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (ar[i] < ar[i - 1])
			ans += ar[i - 1] - ar[i], ar[i] = ar[i - 1];
	}
	cout << ans;
	return 0;
}