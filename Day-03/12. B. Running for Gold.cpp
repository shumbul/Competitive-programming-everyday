// Link - https://codeforces.com/contest/1552/problem/B
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

struct Rank {
	int r[5];
};
// rank is a keywork

bool issmaller(Rank a, Rank b) {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (a.r[i] < b.r[i]) {
			cnt++;
			if (cnt == 3)
				break;
		}
	}
	return cnt >= 3;
}

void solve() {
	int n;	cin >> n;
	vector<Rank> ar(n);
	for0(i, n) for0(j, 5)	cin >> ar[i].r[j];
	int gold = 0;
	for1(i, n - 1) {
		if (issmaller(ar[i], ar[gold]))
			gold = i;
	}
	// checking if gold is actually superior to all
	for0(i, n) {
		if (i == gold)
			continue;
		if (issmaller(ar[i], ar[gold])) {
			cout << "-1\n";
			return;
		}
	}
	cout << gold + 1 << "\n";
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	while (t--) solve();
	return 0;
}