// Link - https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/reunion-of-1s-1b5bd063/
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

vi ar(100001);
vi par(100001);
vi r(100001);

int find(int a) {
	if (par[a] < 0)
		return a;
	return find(par[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)
		return;
	if (r[a] >= r[b]) {
		r[a] += r[b];
		par[b] = a;
	}
	else {
		r[b] += r[a];
		par[a] = b;
	}
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;	cin >> n >> k;
	int mx = 0;
	string s;	cin >> s;
	for1(i, n) {
		ar[i] = 0, par[i] = -1, r[i] = 1;
	}
	for1(i, n) {
		if (s[i - 1] == '1')
			ar[i] = 1;
		if (ar[i] == 1) {
			par[i] = -1;
			r[i] = 1;
			if (i > 1 && ar[i - 1] == 1) {
				merge(i, i - 1);
			}
			int p = find(i);
			mx = max(mx, r[p]);
		}
	}
	int a;
	while (k--) {
		cin >> a;
		if (a == 1)
			cout << mx << '\n';
		else {
			cin >> a;
			if (ar[a] == 1)
				continue;
			ar[a] = 1;
			par[a] = -1;
			r[a] = 1;
			if (a > 1 && ar[a - 1] == 1)
				merge(a, a - 1);
			if (a < n && ar[a + 1] == 1)
				merge(a, a + 1);
			int p = find(a);
			mx = max(mx, r[p]);
		}
	}

	return 0;
}