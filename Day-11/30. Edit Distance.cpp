// Link - https://practice.geeksforgeeks.org/problems/edit-distance3702/1
// Author - Shumbul Arifa

int editDistance(string s, string t) {
	// Code here
	int slen = s.length(), tlen = t.length();
	int dp[slen + 1][tlen + 1];
	for (int i = 0; i <= slen; i++) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= tlen; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= slen; i++) {
		for (int j = 1; j <= tlen; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1, dp[i - 1][j] + 1});
			}
		}
	}

	// for(int i=0;i<=slen;i++){
	//     for(int j=0;j<=tlen;j++){
	//         cout<<dp[i][j]<<" ";
	//     }
	//     cout<<"\n";
	// }

	return dp[slen][tlen];
}