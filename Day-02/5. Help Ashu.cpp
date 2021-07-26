// Link - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/
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

int ar[100001], st[400004];

void build_seg_tree(int si, int ss, int se) {
	if (ss == se) {
		st[si] = ar[ss] % 2;
		return;
	}
	int mid = (se - ss) / 2 + ss;
	build_seg_tree(2 * si, ss, mid);
	build_seg_tree(2 * si + 1, mid + 1, se);

	int odds = 0;
	for (int i = ss; i <= se; i++) {
		odds += ar[i] % 2;
	}
	st[si] = odds;
}

int query(int si, int ss, int se, int qs, int qe) {
	// 3 cases
	// no overlap
	if (ss > qe || se < qs) {
		return 0;
	}
	// range complete overlaps inside query
	if ( qs <= ss && qe >= se) {
		return st[si];
	}
	int mid = (se - ss) / 2 + ss;
	return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}

void update_segtree(int si, int ss, int se, int qi) {
	if (ss == se) {
		st[si] = ar[ss] % 2;
		return;
	}
	int mid = (se - ss) / 2 + ss;
	if (qi <= mid)
		update_segtree(2 * si, ss, mid, qi);
	else
		update_segtree(2 * si + 1, mid + 1, se, qi);
	st[si] = st[2 * si] + st[2 * si + 1];
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;	cin >> n;
	for1(i, n)	cin >> ar[i];
	build_seg_tree(1, 1, n);
	int q;	cin >> q;
	while (q--) {
		// for1(i, 4 * n) {
		// 	cout << st[i] << "->";
		// }
		// cout << "\n";
		int c, x, y;
		cin >> c >> x >> y;
		if (c == 0) {
			if (y % 2 == ar[x] % 2)
				continue;
			ar[x] = y;
			update_segtree(1, 1, n, x);
		}
		else {
			int odd = query(1, 1, n, x, y);
			if (c == 1)
				cout << y - x + 1 - odd << "\n";
			else
				cout << odd << "\n";
		}
	}

	return 0;
}