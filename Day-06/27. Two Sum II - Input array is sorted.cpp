// Link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author - Shumbul Arifa

class Solution {
	int bin_search(vector<int>& nums, int i, int target) {
		int l = i + 1, h = nums.size() - 1, mid;
		while (l <= h) {
			mid = (h - l) / 2 + l;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] < target)
				l = mid + 1;
			else
				h = mid - 1;
		}
		return -1;
	}
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			int bs = bin_search(nums, i, target - nums[i]);
			if (bs != -1)
				return {i + 1, bs + 1};
		}
		return { -1, -1};
	}
};