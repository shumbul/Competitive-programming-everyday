// Link - https://www.spoj.com/STCBASIC/problems/BUSYMAN/
// Author - Shumbul Arifa

// Link -
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
		int n;	cin >> n;
		int s, e;
		vector<pair<int, int>> v;
		for0(i, n) {
			cin >> s >> e;
			v.push_back({e, s});
		}
		sort(v.begin(), v.end());
		int time = 0, ans = 0;
		for (auto a : v) {
			if (a.second >= time) {
				ans++;
				time = a.first;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}