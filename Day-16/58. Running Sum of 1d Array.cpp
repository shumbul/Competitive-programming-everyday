// Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3730/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n);
		ans[0] = nums[0];
		for (int i = 1; i < n; i++)
			ans[i] = ans[i - 1] + nums[i];
		return ans;
	}
};