// Link - https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1144/
// Author - Shumbul Arifa

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int n = nums.size();
		vector<int> left_sum(n), right_sum(n);
		for (int i = 1; i < n; i++) {
			left_sum[i] = left_sum[i - 1] + nums[i - 1];
		}
		for (int i = n - 2; i >= 0; i--) {
			right_sum[i] = right_sum[i + 1] + nums[i + 1];
		}
		for (int i = 0; i < n; i++) {
			if (left_sum[i] == right_sum[i])
				return i;
		}
		return -1;
	}
};