// Link - https://cses.fi/problemset/task/1623
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
	vector<int> v(n);
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s += v[i];
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		int cs = 0;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1)
				cs += v[j];
		}
		if (cs <= s / 2)
			ans = max(ans, cs);
	}
	cout << s - 2 * ans;
	return 0;
}