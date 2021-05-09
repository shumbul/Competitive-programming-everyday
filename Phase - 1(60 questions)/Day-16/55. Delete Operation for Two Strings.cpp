// Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3734/
// Author - Shumbul Arifa

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        if (!n1)
            return n2;
        if (!n2)
            return n1;
        int dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));
        int maxl = 0;
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxl = max(maxl, dp[i][j]);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return (n1 - maxl + n2 - maxl);
    }
};