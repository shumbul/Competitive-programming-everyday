// Link - https://codeforces.com/contest/1395/problem/C
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

	int na, nb;
	cin >> na >> nb;
	vector<int> a(na), b(nb);
	for0(i, na)	cin >> a[i];
	for0(i, nb)	cin >> b[i];
	int A;
	for (A = 0; A < mod; A++) {
		bool isAns = true;
		for0(i, na) {
			bool flag = false;
			for0(j, nb) {
				if (((a[i]&b[j]) | A) == A) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				isAns = false;
				break;
			}
		}
		if (isAns) {
			cout << A;
			return 0;
		}
	}
	return 0;
}

// BRUTE FORCE - TLE with large inputs
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;
int mini = INT_MAX;

void calc(int i, vector<int> a, vector<int> b, int na, int nb, int val) {
	if (i == na) {
		mini = min(mini, val);
		return;
	}
	for (int j = 0; j < nb; j++) {
		calc(i + 1, a, b, na, nb, val | (a[i]&b[j]));
	}
}


signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int na, nb;
	cin >> na >> nb;
	vector<int> a(na), b(nb);
	for0(i, na)	cin >> a[i];
	for0(i, nb)	cin >> b[i];
	int i = 0;
	calc(i, a, b, na, nb, i);
	cout << mini;

	return 0;
}