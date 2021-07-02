// Link - https://www.geeksforgeeks.org/minimize-elements-to-be-added-to-a-given-array-such-that-it-contains-another-given-array-as-its-subsequence/
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

int solve(vector<int> A, int n1, vector<int> B, int n2) {
	int ans = 0;
	if (n2 == 0)
		return n1;
	int dp[n1 + 1][n2 + 1];
	for (int i = 0; i <= n1; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= n2; i++)
		dp[0][i] = 0;
	// LCS length
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	// B is this much far from letting A be it's subsequence
	return n1 - dp[n1][n2];
}
signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n1, n2;	cin >> n1 >> n2;
	vector<int> A(n1), B(n2);
	for (int i = 0; i < n1; i++)
		cin >> A[i];
	for (int i = 0; i < n2; i++)
		cin >> B[i];
	cout << solve(A, n1, B, n2);

	return 0;
}