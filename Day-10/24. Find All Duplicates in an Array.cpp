// Link - https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Author - Shumbul Arifa

lass Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		auto ar = nums;
		int n = ar.size();
		vector<int> ans;
		int m = -1;
		for (int i = 0; i < n; i++) {
			if (ar[abs(ar[i]) - 1] > 0)
				ar[abs(ar[i]) - 1] = ar[abs(ar[i]) - 1] * m;
			else {
				ans.push_back(abs(ar[i]));
			}
		}
		return ans;
	}
};