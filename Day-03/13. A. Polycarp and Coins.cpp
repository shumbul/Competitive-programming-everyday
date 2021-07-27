// Link - https://codeforces.com/contest/1551/problem/A
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

void solve() {
	int n;	cin >> n;
	int rem = n % 3, n1, n2;
	if (rem == 0)
		n1 = n / 3, n2 = n - 2 * n1;
	else if (rem == 1)
		n1 = n / 3 + 1, n2 = n / 3;
	else
		n1 = n / 3, n2 = n / 3 + 1;
	cout << n1 << " " << n2 << "\n";
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	while (t--)
		solve();

	return 0;
}