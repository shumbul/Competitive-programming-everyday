// Link - https://www.interviewbit.com/problems/0-1-knapsack/
// Author - Shumbul Arifa

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
	int n = A.size();
	if (n == 0 || C == 0)
		return 0;
	int dp[n + 1][C + 1];
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;

	for (int i = 1; i <= C; i++)
		dp[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= C; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (B[i - 1] <= j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - B[i - 1]] + A[i - 1]);
		}
	}
	return dp[n][C];
}