// Link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int t) {
		vector<int> ans;
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			if (nums[i] + nums[j] == t) {
				ans.push_back(i + 1);
				ans.push_back(j + 1);
			}
			if (nums[i] + nums[j] < t)
				i++;
			else j--;
		}
		return ans;
	}
};