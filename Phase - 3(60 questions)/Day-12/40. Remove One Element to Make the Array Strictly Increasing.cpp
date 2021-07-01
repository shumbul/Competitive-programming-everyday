// Link - https://leetcode.com/contest/biweekly-contest-55/problems/remove-one-element-to-make-the-array-strictly-increasing/
// Author - Shumbul Arifa

class Solution {
public:
	bool canBeIncreasing(vector<int>& nums) {
		// vector<int> prob;
		int idx = -1, cnt = 0;
		// basic
		int n = nums.size();
		if (n < 3)
			return true;
		if (n == 3) {
			for (int i = 1; i < 3; i++) {
				if (nums[i] > nums[i - 1])
					return true;
			}
			return false;
		}
		for (int i = 1; i < n; i++) {
			if (nums[i] <= nums[i - 1]) {
				// prob.push_back(i);
				idx = i;
				cnt++;
			}
		}
		if (cnt > 1)
			return false;
		if (idx == 1 || idx == n || idx == n - 1 || cnt == 0)
			return true;
		// checking if 1 element can be removed
		if (nums[idx + 1] > nums[idx - 1] || nums[idx] > nums[idx - 2])
			return true;
		return false;
	}
};