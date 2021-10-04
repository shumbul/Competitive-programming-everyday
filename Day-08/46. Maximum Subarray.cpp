// Link -https://leetcode.com/problems/maximum-subarray/
// Author - Shumbul Arifa

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int mtn = INT_MIN, max_cont = 0, i, n = nums.size();
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (nums[i] > 0)
				flag = false;
			mtn = max(mtn, nums[i]);
		}
		if (flag) {
			return mtn;
		}
		for (int i = 0; i < n; i++) {
			max_cont = max_cont + nums[i];
			mtn = max(max_cont, mtn);
			if (max_cont < 0)
				max_cont = 0;
		}
		return mtn;
	}
};