// Link - https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		unordered_map<int, int> mp;
		auto a = nums;
		sort(a.begin(), a.end());
		int k = 0;
		for (int i : a) {
			if (mp.find(i) == mp.end())
				mp[i] = k;
			k++;
		}
		vector<int> ans;
		for (int i : nums)
			ans.push_back(mp[i]);
		return ans;
	}
};