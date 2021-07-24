// Link - https://cses.fi/problemset/task/1072/
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
	for (int k = 1; k <= n; k++) {
		int a1 = k * k;
		int a2 = (a1 * (a1 - 1)) / 2;
		if (k > 2)
			a2 = a2 - 4 * (k - 1) * (k - 2);
		cout << a2 << "\n";
	}

	return 0;
}