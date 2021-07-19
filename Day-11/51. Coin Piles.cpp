// Link - https://cses.fi/problemset/task/1754
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

void solve(int a, int b) {
	if (a > b) {
		solve(b, a);
		return;
	}
	if (!a && !b) {
		cout << "YES\n";
	}
	else if (!a || !b || (a + b) % 3 != 0) {
		cout << "NO\n";
	}
	else if (b <= 2 * a) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		solve(a, b);
	}

	return 0;
}