// Link - https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
// Author - Shumbul Arifa

class Solution {
public:
	int minDifference(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		if (n <= 3)
			return 0;
		// min diff bw 1st three and last three
		int ans = nums[n - 1] - nums[0];
		for (int i = 0, j = n - 4; j < n; j++, i++) {
			ans = min(ans, nums[j] - nums[i]);
		}
		return ans;
	}
};