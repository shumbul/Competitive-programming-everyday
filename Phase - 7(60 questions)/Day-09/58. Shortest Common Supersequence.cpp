// Link - https://binarysearch.com/problems/Shortest-Common-Supersequence
// Author - Shumbul Arifa

int solve(string a, string b) {
	int l1 = a.length(), l2 = b.length();
	int dp[l1 + 1][l2 + 1];
	for (int i = 0; i <= l1; i++) dp[i][0] = 0;
	for (int i = 0; i <= l2; i++) dp[0][i] = 0;
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int k = dp[l1][l2];
	cout << k;
	return l1 + l2 - k;
}