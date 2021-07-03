// Link - https://leetcode.com/problems/subsets/
// Author - Shumbul Arifa

class Solution {
	vector<vector<int>> ans; // {{}, {1}, {2}, {3}, {1,2}, {1,3}}
	int k;
	void backtrack(vector<int> &nums, int first, vector<int> curr) {
		// base case
		if (curr.size() == k) {
			ans.push_back(curr);
			return;
		}
		// main algo
		for (int i = first; i < nums.size(); i++) {
			curr.push_back(nums[i]);
			backtrack(nums, i + 1, curr);
			// this
			curr.pop_back();
		}
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		// M-2 Backtracking
		vector<int> curr;
		for (k = 0; k <= nums.size(); k++) {
			curr = {};
			backtrack(nums, 0, curr);
		}
		return ans;
	}
};