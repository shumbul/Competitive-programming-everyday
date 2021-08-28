// Link - https://leetcode.com/problems/sort-array-by-parity/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		int i = 0, j = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] % 2 == 0) {
				swap(nums[i], nums[j]);
				j++;
			}
		}
		return nums;
	}
};