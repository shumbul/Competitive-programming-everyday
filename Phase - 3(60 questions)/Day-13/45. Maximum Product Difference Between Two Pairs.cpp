// Link - https://leetcode.com/contest/weekly-contest-247/problems/maximum-product-difference-between-two-pairs/
// Author - Shumbul Arifa

class Solution {
public:
	int maxProductDifference(vector<int>& nums) {
		int x, y, z, w;
		auto a = max_element(nums.begin(), nums.end());
		x = *a;
		*a = -1;
		auto b = max_element(nums.begin(), nums.end());
		y = *b;
		*a = x;
		a = min_element(nums.begin(), nums.end());
		z = *a;
		*a = 10003;
		b = min_element(nums.begin(), nums.end());
		w = *b;
		*b = w;
		return (x * y - z * w);
	}
};