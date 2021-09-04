// Link - https://www.codechef.com/problems/CSUB
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
	int ans = 0;
	int n;	cin >> n;
	string s;	cin >> s;
	for (char c : s)
		if (c == '1')
			ans++;
	return (ans * (ans + 1)) / 2;
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