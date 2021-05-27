// Link -https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		auto ar = nums;
		int n = ar.size();
		vector<int> ans;
		int m = -1;
		for (int i = 0; i < n; i++) {
			if (ar[abs(ar[i]) - 1] > 0)
				ar[abs(ar[i]) - 1] = ar[abs(ar[i]) - 1] * m;
		}
		for (int i = 0; i < n; i++) {
			if (ar[i] > 0) {
				ans.push_back(i + 1);
			}
			cout << ar[i] << " ";
		}
		return ans;
	}
};