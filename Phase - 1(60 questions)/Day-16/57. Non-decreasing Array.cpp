// Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3731/
// Author - Shumbul Arifa

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		bool f = 0;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				if (i == 0) {
					f = 1;
					nums[i] = nums[i + 1];
					continue;
				}
				if (f)
					return false;
				f = 1;
				if (nums[i + 1] >= nums[i - 1] && i > 0 && i < nums.size() - 1)
					nums[i] = nums[i + 1];
				else if (nums[i + 1] < nums[i - 1] && i > 0 && i < nums.size() - 1)
					nums[i + 1] = nums[i];
			}
		}
		return true;
	}
};