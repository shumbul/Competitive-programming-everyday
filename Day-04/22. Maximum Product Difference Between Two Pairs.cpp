// Link - https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
// Author - Shumbul Arifa

class Solution {
public:
	int maxProductDifference(vector<int>& nums) {
		auto a = nums;
		sort(a.begin(), a.end());
		int n = nums.size();
		return (a[n - 2] * a[n - 1] - a[0] * a[1]);
	}
};