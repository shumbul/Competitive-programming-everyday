// Link - https://codeforces.com/contest/1283/problem/C
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

int ar[200002];

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;	cin >> n;
	for1(i, n)	cin >> ar[i];
	vector<int> s1;
	set<int> s2;
	for1(i, n)	s2.insert(i);
	for1(i, n) {
		if (ar[i] == 0)
			s1.pb(i);
		else
			s2.erase(ar[i]);
	}
	vector<int> v2;
	for (auto b : s2) {
		v2.pb(b);
	}
	s2.clear();
	// for (int i = 0; i < (int)s1.size(); i++)
	// 	cout << s1[i] << " " << v2[i] << "\n";
	// cout << "\n\n";
	for (int i = 0; i < (int)s1.size(); i++) {
		if (s1[i] == v2[i]) {
			if (i == 0) {
				swap(v2[i], v2[i + 1]);
			}
			else {
				swap(v2[i], v2[i - 1]);
			}
		}
	}
	for (int i = 0; i < (int)s1.size(); i++) {
		ar[s1[i]] = v2[i];
	}

	for1(i, n) {
		if (ar[i])
			cout << ar[i] << " ";
	}

	return 0;
}