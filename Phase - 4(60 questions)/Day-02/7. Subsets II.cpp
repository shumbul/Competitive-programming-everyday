// Link - https://leetcode.com/problems/subsets-ii/
// Author - Shumbul Arifa

class Solution {
	vector<vector<int>> ans; // {{}, {1}, {2}, {3}, {1,2}, {1,3}}
	set<vector<int>> st;
	int k;
	void backtrack(vector<int> &nums, int first, vector<int> curr) {
		// base case
		if (curr.size() == k) {
			sort(curr.begin(), curr.end());
			st.insert(curr);
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
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<int> curr;
		st.clear();
		ans.clear();
		for (k = 0; k <= nums.size(); k++) {
			curr = {};
			backtrack(nums, 0, curr);
		}
		for (auto a : st) {
			ans.push_back(a);
		}
		return ans;
	}
};