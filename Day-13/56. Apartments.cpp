// Link - https://cses.fi/problemset/result/2565500/
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

	int n, m, k;	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for0(i, n)
	cin >> a[i];
	for0(i, m)
	cin >> b[i];

	int ans = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0, j = 0; i < n; i++) {
		while (j < m && b[j] < a[i] - k)
			j++;
		if (j < m && b[j] <= a[i] + k)
			ans++, j++;
	}
	cout << ans;

	return 0;
}