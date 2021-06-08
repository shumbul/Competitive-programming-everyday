// Link - https://www.interviewbit.com/problems/repeating-subsequence/
// Author - Shumbul Arifa

int Solution::anytwo(string A) {
	int n = A.length(), dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
		dp[i][0] = dp[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && A[i - 1] == A[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	// for(int i=0;i<=n;i++){
	//     for(int j=0;j<=n;j++)
	//         cout<<dp[i][j]<<" ";
	//     cout<<"\n";
	// }
	return dp[n][n] >= 2;
}