// Link - https://www.interviewbit.com/problems/flip-array/
// Author - Shumbul Arifa

#include<bits/stdc++.h>
int Solution::solve(const vector<int> &A) {
	int n = A.size();
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	int s = accumulate(A.begin(), A.end(), 0) / 2;
	long long dp[n + 1][s + 1];
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= s; i++)
		dp[0][i] = INT_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= s; j++) {
			dp[i][j] = dp[i - 1][j];
			if (A[i - 1] <= j) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - A[i - 1]] + 1);
			}
		}
	}
	// for(int i=0;i<=n;i++){
	//     for(int j=0;j<=s;j++)
	//         cout<<dp[i][j]<<" ";
	//     cout<<"\n";
	// }

	return dp[n][s];
}


// Editorial solution
int Solution::solve(const vector<int> &A) {
	int sum = 0;
	for (int i = 0; i < A.size(); i++) sum += A[i];
	sum /= 2;
	vector<int> dp(sum + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = sum; j >= A[i]; j--)
		{
			if (dp[j - A[i]] != INT_MAX) dp[j] = min(dp[j], dp[j - A[i]] + 1);
		}
	}
	for (int i = sum; i >= 0 ; i--)
	{
		if (dp[i] != INT_MAX) return dp[i];
	}

}
