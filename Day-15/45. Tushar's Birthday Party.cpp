// Link - https://www.interviewbit.com/problems/tushars-birthday-party/
// Author - Shumbul Arifa

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	int n1 = *max_element(A.begin(), A.end()), n2 = B.size(), n3 = C.size();
	if (n2 != n3)
		return -1;
	int dp[n2 + 1][n1 + 1];
	for (int i = 0; i <= n2; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= n1; i++)
		dp[0][i] = 100000001;
	for (int i = 1; i <= n2; i++) {
		for (int j = 1; j <= n1; j++) {
			if (B[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = min(dp[i][j - B[i - 1]] + C[i - 1], dp[i - 1][j]);
			}
		}
	}
	// for(int i=0;i<=n2;i++) {
	//     for(int j=0;j<=n1;j++)
	//         cout<<dp[i][j]<<" ";
	//     cout<<"\n";
	// }
	int ans = 0;
	for (int a : A)
		ans += dp[n2][a];
	return ans;
}