// Link - https://www.codechef.com/problems/CARVANS
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

int solve() {
	int n;	cin >> n;
	if (!n)
		return n;
	vi a(n);
	for0(i, n)	cin >> a[i];
	int m = a[0];
	int ans;
	ans = 1;
	for1(i, n - 1) {
		if (a[i] <= m) {
			ans++;
		}
		m = min(m, a[i]);
	}
	return ans;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	while (t--) {
		cout << solve() << "\n";
	}

	return 0;
}