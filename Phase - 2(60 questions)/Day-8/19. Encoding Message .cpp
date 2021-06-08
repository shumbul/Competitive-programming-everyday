// Link - https://www.codechef.com/WICP2002/problems/ENCOMS
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

void solve() {
	int n;
	string s;	cin >> n >> s;
	for (unsigned int i = 1; i < s.length(); i += 2) {
		auto a = 122 - s[i] + 'a';
		auto b = 122 - s[i - 1] + 'a';
		s[i] = b, s[i - 1] = a;
	}
	cout << s << "\n";
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}