// Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3732/
// Author - Shumbul Arifa

class Solution {
	vector<int> dp;
	int minsans;
	int f(vector<int>& nums, int curr) {
		dp[0] = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
				dp[i + j] = min(dp[i + j], dp[i] + 1);
			}
		}
		return dp[nums.size() - 1];
	}
public:
	int jump(vector<int>& nums) {
		dp.resize(nums.size());
		for (int i = 0; i < nums.size(); i++)
			dp[i] = INT_MAX;
		return f(nums, 0);
	}
};