// Link - https://leetcode.com/problems/3sum/
// Author - Shumbul Arifa

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		if (nums.size() < 3)   return ans;
		map<int, int> mp;
		int i = 0;
		sort(nums.begin(), nums.end());
		for (auto v : nums) {
			mp[v] = i++;
		}
		vector<int> v;
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i - 1] == nums[i]) continue;
			for (int j = i + 1; j < nums.size(); j++) {
				int sum2 = nums[i] + nums[j];
				if (mp.find(sum2 * -1) != mp.end()) {
					if (mp[sum2 * -1] > j) {
						v = {nums[i], nums[j], sum2 * -1};
						ans.push_back(v);
					}
				}
			}
		}
		//delete dups from ans
		set<vector<int>> s;
		for (auto a : ans) {
			s.insert(a);
		}
		ans.clear();
		for (auto a : s) {
			ans.push_back(a);
		}
		return ans;
	}
};