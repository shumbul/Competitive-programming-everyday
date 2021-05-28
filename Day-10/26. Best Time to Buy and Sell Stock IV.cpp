// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Author - Shumbul Arifa

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		if (n < 2)
			return 0;
		k = min(n, k);
		int dp[k + 1][n];
		for (int i = 0; i <= k; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = 0;

		for (int i = 1; i <= k; i++) {
			for (int j = 1; j < n; j++) {
				int sale = dp[i][j - 1];
				for (int p = 0; p < j; p++) {
					int pr = prices[j] - prices[p];
					sale = max(sale, pr + dp[i - 1][p]);
				}
				dp[i][j] = sale;
			}
		}

		for (int i = 0; i <= k; i++) {
			for (int j = 0; j < n; j++)
				cout << dp[i][j] << " ";
			cout << "\n";
		}

		return dp[k][n - 1];
	}
};