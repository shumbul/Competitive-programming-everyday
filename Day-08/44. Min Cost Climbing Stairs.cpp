// Link - https://leetcode.com/problems/min-cost-climbing-stairs/
// Author - Shumbul Arifa

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		cost.push_back(0);
		int n = cost.size(), dp[n];
		dp[0] = cost[0], dp[1] = cost[1];
		for (int i = 2; i < n; i++) {
			dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
		}
		return dp[n - 1];
	}
};