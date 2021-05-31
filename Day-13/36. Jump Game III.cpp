// Link - https://leetcode.com/problems/jump-game-iii/
// Author - Shumbul Arifa

class Solution {
public:
	bool canReach(vector<int>& nums, int start) {
		int n = nums.size();
		if (start < 0 || start >= n || nums[start] < 0)
			return false;
		if (nums[start] == 0)
			return true;
		int i = start;
		nums[i] *= -1;
		return canReach(nums, i + nums[i]) || canReach(nums, i - nums[i]);
		return false;
	}
};