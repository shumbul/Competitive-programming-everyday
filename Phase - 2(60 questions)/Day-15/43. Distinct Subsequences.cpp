// Link - https://www.interviewbit.com/problems/distinct-subsequences/
// Author - Shumbul Arifa

int Solution::numDistinct(string A, string B) {
	int n = A.length(), m = B.length();
	int dp[m + 1][n + 1];
	for (int i = 0; i <= n; i++)
		dp[0][i] = 1;
	for (int j = 1; j <= m; j++)
		dp[j][0] = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (B[i - 1] == A[j - 1])
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i][j - 1];
		}
	}
	// for(int i=0;i<=m;i++){
	//     for(int j=0;j<=n;j++)
	//         cout<<dp[i][j]<<" ";
	//     cout<<"\n";
	// }
	return dp[m][n];
}