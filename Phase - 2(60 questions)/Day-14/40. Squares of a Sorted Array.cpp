// Link - https://leetcode.com/problems/squares-of-a-sorted-array/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int i = 0, j = nums.size() - 1, k = j;
		vector<int> ans(nums.size());
		while (i <= j) {
			if (abs(nums[i]) >= abs(nums[j]))
				ans[k--] = nums[i] * nums[i++];
			else
				ans[k--] = nums[j] * nums[j--];
		}
		return ans;
	}
};