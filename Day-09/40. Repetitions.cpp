// Link - https://cses.fi/problemset/task/1069/
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
	string s;	cin >> s;
	int ans = 0, cnt = 0;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (i == 0)
			cnt = 1;
		else if (s[i] == s[i - 1]) {
			cnt++;
		}
		else {
			ans = max(ans, cnt);
			cnt = 1;
		}
	}
	cout << max(ans, cnt);
	return 0;
}