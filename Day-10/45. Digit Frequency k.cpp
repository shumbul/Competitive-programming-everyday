// Link - https://www.youtube.com/watch?v=L1ZC9MI5yhY
// Author - Shumbul Arifa

// Return the count of integers in range [0,X] which have frequency of digit d is equal to k
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

int l, r, k, d;
vi v;
int dp[20][165][2];

int solve(int pos, int freq, bool cond) {
	if (pos == (int)v.size())
		return freq == k;
	if (dp[pos][freq][cond] != -1)
		return dp[pos][freq][cond];
	int limit = 9;
	if (!cond)	limit = v[pos];
	int cnt = 0;
	for (int i = 0; i <= limit; i++) {
		int new_freq = freq;
		if (i == d)
			new_freq++;
		if (cond || i < limit) {
			cnt += solve(pos + 1, new_freq, true);
		}
		else
			cnt += solve(pos + 1, new_freq, false);
	}
	return dp[pos][freq][cond] = cnt;
}

int getAns(int num) {
	v.clear();
	memset(dp, -1, sizeof dp);
	while (num) {
		v.insert(v.begin(), num % 10);
		num /= 10;
	}
	int ans = solve(0, 0, false);
	return ans;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> l >> r >> d >> k;
	int ans = getAns(r) - getAns(l - 1);
	cout << ans << "\n";

	return 0;
}