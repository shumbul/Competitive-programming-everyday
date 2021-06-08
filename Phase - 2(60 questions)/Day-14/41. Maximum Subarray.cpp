// Link - https://leetcode.com/problems/maximum-subarray/
// Author - Shumbul Arifa

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int curr = -100001, maxi = curr;
		for (auto i : nums) {
			curr = max(i, curr + i);
			maxi = max(maxi, curr);
		}
		return maxi;
	}
};