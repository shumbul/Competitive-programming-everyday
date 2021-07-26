// Link - https://www.codechef.com/problems/MULTQ3
// Author - Shumbul Arifa

// Lazy Propagation
#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

struct node {
	int ar[3];
};

int ar[100001], lazy[100001];
node st[400004];
// we can also use st[400004][3]

void build_seg_tree(int si, int ss, int se) {
	if (ss == se) {
		st[si].ar[0] = 1;	// initially, all are 0
		st[si].ar[1] = 0;
		st[si].ar[2] = 0;
		return;
	}
	int mid = (se - ss) / 2 + ss;
	build_seg_tree(2 * si, ss, mid);
	build_seg_tree(2 * si + 1, mid + 1, se);
	st[si].ar[0] = st[2 * si].ar[0] + st[2 * si + 1].ar[0];
	st[si].ar[1] = st[2 * si].ar[1] + st[2 * si + 1].ar[1];
	st[si].ar[2] = st[2 * si].ar[2] + st[2 * si + 1].ar[2];
}

void shift(int si) {
	int a = st[si].ar[0];
	st[si].ar[0] = st[si].ar[2];
	st[si].ar[2] = st[si].ar[1];
	st[si].ar[1] = a;
}

void update(int si, int ss, int se, int qs, int qe) {
	if (lazy[si] != 0) {
		int add = lazy[si];
		lazy[si] = 0;
		add %= 3;
		if (ss != se) {
			// not a leaf node
			lazy[2 * si] = (lazy[2 * si] + add) % 3;
			lazy[2 * si + 1] = (lazy[2 * si + 1] + add) % 3;
		}
		for (int i = 0; i < add; i++)
			shift(si);
	}
	// we only process on updated seg tree
	if (ss > qe || se < qs)
		return;

	if (ss >= qs && se <= qe) {
		shift(si);
		if (ss != se) {
			lazy[2 * si] = (lazy[2 * si] + 1) % 3;
			lazy[2 * si + 1] = (lazy[2 * si + 1] + 1) % 3;
		}
		return;
	}

	int mid = (se - ss) / 2 + ss;
	update(2 * si, ss, mid, qs, qe);
	update(2 * si + 1, mid + 1, se, qs, qe);
	st[si].ar[0] = st[2 * si].ar[0] + st[2 * si + 1].ar[0];
	st[si].ar[1] = st[2 * si].ar[1] + st[2 * si + 1].ar[1];
	st[si].ar[2] = st[2 * si].ar[2] + st[2 * si + 1].ar[2];
}

int query(int si, int ss, int se, int qs, int qe) {
	if (lazy[si] != 0) {
		int add = lazy[si];
		lazy[si] = 0;
		add %= 3;
		if (ss != se) {
			// not a leaf node
			lazy[2 * si] = (lazy[2 * si] + add) % 3;
			lazy[2 * si + 1] = (lazy[2 * si + 1] + add) % 3;
		}
		for (int i = 0; i < add; i++)
			shift(si);
	}
	// we only process on updated seg tree
	if (ss > qe || se < qs)
		return 0;

	if (ss >= qs && se <= qe) {
		return st[si].ar[0];
	}

	int mid = (se - ss) / 2 + ss;
	int l = query(2 * si, ss, mid, qs, qe);
	int r = query(2 * si + 1, mid + 1, se, qs, qe);
	return l + r;
}

int main() {
// 	fast;
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n;	cin >> n;
	build_seg_tree(1, 1, n);
	int q;	cin >> q;
	while (q--) {
		int c, a, b;
		cin >> c >> a >> b;
		if (c == 0) {
			for (int i = a; i <= b; i++)
				ar[i] += 1;
			update(1, 1, n, a + 1, b + 1);	// 0 based indexing in inputs
		}
		else {
			cout << query(1, 1, n, a + 1, b + 1) << "\n";
		}
	}

	return 0;
}