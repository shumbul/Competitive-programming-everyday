// Link - https://cses.fi/problemset/task/1090
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

	int n, w;	cin >> n >> w;
	vector<int> c(n);
	for0(i, n)
	cin >> c[i];
	sort(c.begin(), c.end());
	int ans = 0;
	for (int i = 0, j = n - 1; i < n;) {
		while (i < j && c[i] + c[j] > w)
			j--;
		if (i >= j)	break;
		ans++, i++, j--;
	}
	cout << n - ans;

	return 0;
}