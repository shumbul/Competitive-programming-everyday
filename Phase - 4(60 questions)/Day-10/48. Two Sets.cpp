// Link - https://cses.fi/problemset/task/1092
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
	int tot = (n * (n + 1)) / 2;
	if (tot % 2) {
		cout << "NO";
		return 0;
	}
	// n -> 0 or 3 mod 4
	// we get a 4 in n*(n+1) in both of these
	int j;
	vector<int> v1, v2;
	if (n % 4) {
		j = 3;
		v1.pb(1);
		v1.pb(2);
		v2.pb(3);
	}
	else {
		j = 4;
		v1.pb(1);
		v1.pb(4);
		v2.pb(2);
		v2.pb(3);
	}
	// if j==3:
	// {1,2} {3}
	// if j==4:
	// {1,4} {2,3}

	for (int i = 0; i < (n - 1) / 4; i++) {
		v1.pb(4 * i + 1 + j);
		v1.pb(4 * i + 4 + j);
		v2.pb(4 * i + 2 + j);
		v2.pb(4 * i + 3 + j);
	}
	cout << "YES\n" << v1.size() << "\n";
	for (int i : v1)
		cout << i << " ";
	cout << "\n" << v2.size() << "\n";
	for (int i : v2)
		cout << i << " ";
	return 0;
}