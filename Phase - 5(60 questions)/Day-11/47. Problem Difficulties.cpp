// Link - https://www.codechef.com/AUG21C/problems/PROBDIFF
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
		int a1, a2, a3, a4;
		cin >> a1 >> a2 >> a3 >> a4;
		unordered_map<int, int> mp;
		mp[a1]++, mp[a2]++, mp[a3]++, mp[a4]++;
		if (mp.size() == 1) {
			cout << "0\n";
			continue;
		}
		priority_queue<int> pq;
		for (auto a : mp) {
			pq.push(a.second);
		}
		int ans = 0;
		while (pq.size() > 1) {
			auto a1 = pq.top();
			pq.pop();
			auto a2 = pq.top();
			pq.pop();
			int b = min(a1, a2);
			ans += b;
			a1 -= b, a2 -= b;
			if (a1)
				pq.push(a1);
			else if (a2)
				pq.push(a2);
		}
		cout << ans << "\n";
	}

	return 0;
}