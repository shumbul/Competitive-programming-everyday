// Link - https://www.pramp.com/challenge/61ojWAjLJbhob2nP2q1O
// Author - Shumbul Arifa

int deletionDistance( const string& str1, const string& str2 )
{
	// your code goes here
	int dp[str1.length() + 1][str2.length() + 1];
	for (int i = 0; i <= str1.size(); i++) {
		for (int j = 0; j <= str2.size(); j++) {
			if (i == 0 and j == 0)
				dp[i][j] = 0 ;
			else if (i == 0) {
				dp[i][j] = j;
			}
			else if (j == 0)
				dp[i][j] = i;
			else if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min(dp[i - 1][j] , dp[i][j - 1]);
			}
		}

	}
	return dp[str1.size()][str2.size()];
}

// Another approach

int deletionDistance( const string& str1, const string& str2 )
{
	// your code goes here
	// the ques is a variant of longest common subsequence!
	int n = str1.length(), m = str2.length();
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= m; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int lcs = dp[n][m];
	return (n - lcs) + (m - lcs);
}

/*
input:  str1 = "dog", str2 = "frog"
output: 3

input:  str1 = "some", str2 = "some"
output: 0

input:  str1 = "some", str2 = "thing"
output: 9

input:  str1 = "", str2 = ""
output: 0
*/