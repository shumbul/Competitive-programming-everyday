// Link - https://leetcode.com/problems/subarray-product-less-than-k/
// Author - Shumbul Arifa

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k == 0)
			return 0;
		int p = 1, cnt = 0;
		for (int i = 0, j = 0; j < nums.size(); j++) {
			p *= nums[j];
			while (p >= k && i <= j)
				p /= nums[i++];
			cnt += (j - i + 1);
		}
		return cnt;
	}
};