// Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3770/
// Author - Shumbul Arifa

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size(), dp[n + 2];
		if (n < 2)
			return 0;
		dp[0] = 0;
		dp[1] = 0;
		dp[2] = 0;
		for (int i = 2; i <= n; i++) {
			dp[i + 1] = min(dp[i] + cost[i - 1], dp[i - 1] + cost[i - 2]);
		}
		return dp[n + 1];
	}
};