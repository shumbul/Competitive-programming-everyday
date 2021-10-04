// Link - https://leetcode.com/problems/sort-array-by-parity/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		int n = nums.size();
		auto a = nums;
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				swap(a[i], a[j]);
				j++;
			}
		}
		return a;
	}
};