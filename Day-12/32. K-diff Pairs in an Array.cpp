// Link - https://leetcode.com/problems/k-diff-pairs-in-an-array/
// Author - Shumbul Arifa

class Solution {
public:
	int handle0(vector<int>& nums) {
		map<int, int> mp;
		for (int i = 0; i < nums.size(); i++) {
			mp[nums[i]]++;
		}
		int ans = 0;
		for (auto i : mp) {
			if (i.second > 1)
				ans++;
		}
		return ans;
	}
	int findPairs(vector<int>& nums, int k) {
		if (k == 0)
			return handle0(nums);
		set<int> st, ap;
		for (int i = 0; i < nums.size(); i++) {
			st.insert(nums[i]);
		}
		for (int i : st) {
			if (st.find(k + i) != st.end())
				ap.insert(i);
			if (st.find(i - k) != st.end())
				ap.insert(i);
			st.erase(i);
		}
		return ap.size();
