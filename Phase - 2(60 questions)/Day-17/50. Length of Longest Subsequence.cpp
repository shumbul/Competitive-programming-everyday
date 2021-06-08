// Link - https://www.interviewbit.com/problems/length-of-longest-subsequence/
// Author - Shumbul Arifa

int Solution::longestSubsequenceLength(const vector<int> &ar) {
	int n = ar.size();
	if (n == 0)
		return 0;
	int inc[n], dec[n];
	int dp[n];
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (ar[i] > ar[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
	}
	int dp2[n];
	dp2[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = n - 1; j >= i; j--)
			if (ar[i] > ar[j] && dp2[i] < dp2[j] + 1)
				dp2[i] = dp2[j] + 1;
	}

	// for(int i=0;i<n;i++){
	//         cout<<dp[i]<<"  "<<dp2[i]<<"\n";
	// }
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i] + dp2[i] - 1);
	return ans;
}
