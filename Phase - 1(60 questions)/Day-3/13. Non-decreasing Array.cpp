// Link - https://leetcode.com/problems/non-decreasing-array
// Author - Shumbul Arifa

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int dec = 0;
		bool decrease = 0;
		for (int i = 1; i < nums.size(); i++) {
			decrease = 0;
			if (nums[i - 1] > nums[i])
				dec++, decrease = 1;
			if (decrease && i > 1 && nums[i - 2] > nums[i]) {
				if (i < nums.size() - 1 && nums[i - 1] <= nums[i + 1])
					continue;
				if (i != nums.size() - 1)
					dec++;
			}
		}
		return dec < 2;
	}
};