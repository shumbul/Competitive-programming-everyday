// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author - Shumbul Arifa

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int pur = INT_MAX, profit = 0;
		for (int i = 0; i < prices.size(); i++) {
			pur = min(prices[i], pur);
			profit = max(profit, prices[i] - pur);
		}
		return profit;
	}
};