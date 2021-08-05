// Link - https://www.spoj.com/problems/CPCRC1C/
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

string a, b;
int ar[1001];
int dp[11][100][2];

int getAns(int pos, int n, int sum, bool flag) {
	if (pos > n)
		return sum;
	if (dp[pos][sum][flag] != -1)
		return dp[pos][sum][flag];
	int limit = 9;
	if (!flag)	limit = ar[pos];
	int res = 0;
	for (int i = 0; i <= limit; i++) {
		if (flag || i < limit)
			res += getAns(pos + 1, n, sum + i, true);
		else res += getAns(pos + 1, n, sum + i, false);
	}
	return dp[pos][sum][flag] = res;
}

int digitSum(string x) {
	int res = 0;
	for0(i, (int)x.length())
	res += x[i] - '0';
	return res;
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (1) {
		cin >> a >> b;
		if (a == "-1")
			break;
		// digit sum problem is the optimized approach, brute force gives TLE
		for0(i, (int)b.length())	ar[i + 1] = b[i] - '0';
		memset(dp, -1, sizeof dp);
		int ans2 = getAns(1, (int)b.length(), 0, 0);
		for0(i, (int)a.length())	ar[i + 1] = a[i] - '0';
		memset(dp, -1, sizeof dp);
		int ans1 = getAns(1, (int)a.length(), 0, 0);
		cout << ans2 - ans1 + digitSum(a) << "\n";
	}

	return 0;
}