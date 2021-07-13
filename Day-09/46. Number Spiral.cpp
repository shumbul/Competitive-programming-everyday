// Link - https://cses.fi/problemset/task/1071/
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
	int t;	cin >> t;
	while (t--) {
		int y, x;	cin >> y >> x;
		int z = max(y, x);
		int z2 = (z - 1) * (z - 1);
		int ans = 0;
		if (z % 2) {
			if (y == z) {
				ans = z2 + x;	// row wise incrementing pattern
			}
			else {
				ans = z2 + 2 * z - y;	// col wise decrementing pattern
			}
		}
		else {
			if (x == z) {
				ans = z2 + y;	// col wise incrementing pattern
			}
			else {
				ans = z2 + 2 * z - x;	// row wise decrementing pattern
			}
		}
		cout << ans << "\n";
	}
	return 0;
}