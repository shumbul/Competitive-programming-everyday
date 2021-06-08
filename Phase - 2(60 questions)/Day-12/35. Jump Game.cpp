// Link - https://leetcode.com/problems/jump-game/
// Author - Shumbul Arifa

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size(), i, maxj;
		for (i = 0, maxj = 0; i < n && i <= maxj; i++) {
			maxj = max(maxj, i + nums[i]);
		}
		// i>maxj condition arises when reaching i isn't possible.
		return i == n;
	}
};