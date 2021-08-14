// Link - https://www.spoj.com/problems/RMQSQ/
// Author - Shumbul Arifa

// segment tree

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

int ar[100001], st[400004];	// array to store integers of size n and segment tree of size 4n

void build_seg_tree(int si, int ss, int se) {
	if (ss == se) {
		st[si] = ar[ss];
		return;
	}
	int mid = (se - ss) / 2 + ss;
	build_seg_tree(2 * si, ss, mid);
	build_seg_tree(2 * si + 1, mid + 1, se);

	st[si] = min(st[2 * si], st[2 * si + 1]);
}

int query(int si, int ss, int se, int qs, int qe) {
	// 3 cases
	// 1. no overlap
	if (ss > qe || se < qs) {
		return INT_MAX;
	}
	// 2. full overlap
	if (qs <= ss && qe >= se) {
		return st[si];
	}

	// 3. partial overlap
	int mid = (se - ss) / 2 + ss;
	int l = query(2 * si, ss, mid, qs, qe);
	int r = query(2 * si + 1, mid + 1, se, qs, qe);
	return min(l, r);
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, q, l, r;
	cin >> n;
	for1(i, n)	cin >> ar[i];
	build_seg_tree(1, 1, n);
	cin >> q;
	for1(i, q) {
		cin >> l >> r;
		cout << query(1, 1, n, l + 1, r + 1) << "\n";	// added 1 because input is in 0 based index system
	}

	return 0;
}