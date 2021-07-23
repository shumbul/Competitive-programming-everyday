// Link - https://cses.fi/problemset/task/1755
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

void solve(string s) {
	int c[26] = {}, d = 0;
	for (char c1 : s) {
		++c[c1 - 'A'];
	}
	for (int i = 0; i < 26; i++) {
		d += c[i] % 2;
		// cout << (char)(i + 'A') << " " << c[i] << "\n";
	}
	// cout << "d " << d << "\n";
	if (d > 1) {
		cout << "NO SOLUTION\n";
		return;
	}
	string t;
	for (int i = 0; i < 26; i++) {
		if ((c[i] & 1) ^ 1) {
			for (int j = 0; j < c[i] / 2; j++)
				t += i + 'A';
		}
	}
	cout << t;
	reverse(t.begin(), t.end());
	for (int i = 0; i < 26; i++) {
		if (c[i] & 1) {
			for (int j = 0; j < c[i]; j++)
				cout << (char)(i + 'A');
		}
	}
	cout << t;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;	cin >> s;
	solve(s);
	return 0;
}