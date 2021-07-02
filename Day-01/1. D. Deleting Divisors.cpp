// Link - https://codeforces.com/contest/1537/problem/D
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int n) {
	if (n & 1)
		cout << "Bob\n";	// n is odd
	else {
		if (n & (n - 1)) {
			cout << "Alice\n";
			// not a power of 2
		}
		else {
			int c = 1;
			do {
				n = n / 2;
				c++;
			} while (n);
			if (c & 1)
				cout << "Bob\n";
			else
				cout << "Alice\n";
		}
	}
}
signed main() {
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		solve(n);
	}
	return 0;
}