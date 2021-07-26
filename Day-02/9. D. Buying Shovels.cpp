// Link - https://codeforces.com/contest/1360/problem/D
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

// we do brute force till root of n
int solve(int n, int k) {
	if (k == 1)
		return n;
	if (k == 2)
		return n % 2 == 0 ? n / 2 : n;
	// by 2 or by 1
	if (k >= n)
		return 1;
	int m = n, sqt = sqrt(n);
	for (int a = 1; a <= sqt && a <= k; a++) {
		if (n % a == 0) {
			m = min(m, n / a);
			if (n / a <= k)
				return a;
		}
	}
	return m;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	while (t--) {
		int n, k;	cin >> n >> k;
		cout << solve(n, k) << "\n";
	}

	return 0;
}