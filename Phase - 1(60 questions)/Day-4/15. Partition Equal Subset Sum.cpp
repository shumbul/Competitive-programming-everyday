// Link - https://leetcode.com/problems/partition-equal-subset-sum
// Author - Shumbul Arifa

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		// similar to subset problem
		int Sum = accumulate(nums.begin(), nums.end(), 0);
		if (Sum % 2)
			return 0;
		// finding a subset of sum Sum/2 :
		int k = Sum / 2;
		if (*max_element(nums.begin(), nums.end()) > k)
			return 0;
		int n = nums.size(), dp[k + 1];
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = k; j >= nums[i]; j--) {
				if (dp[j] == 0) {
					if (dp[j - nums[i]])
						dp[j] = 1;
				}
			}
		}
		return dp[k];
	}
};