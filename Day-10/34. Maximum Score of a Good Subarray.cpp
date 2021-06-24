// Link - https://leetcode.com/problems/maximum-score-of-a-good-subarray/
// Author - Shumbul Arifa

class Solution {
public:
	int maximumScore(vector<int>& nums, int k) {
		// greedy - O(n) time and O(1) space
		int i = k, j = i;
		int mini = nums[k], ans = mini;
		while (i > 0 || j < nums.size() - 1) {
			if (((i > 0) ? nums[i - 1] : 0) < ((j < (nums.size() - 1)) ? nums[j + 1] : 0))
				mini = min(mini, nums[++j]);
			else
				mini = min(mini, nums[--i]);
			ans = max(ans, mini * (j - i + 1));
		}
		return ans;
	}
	/*
	int maximumScore(vector<int>& nums, int k) {
	    // simple O(n^2) time and O(1) space solution
	    long long ans = nums[k];
	    for(long long i=0;i<=k;i++){
	        for(long long j=k;j<nums.size();j++)
	            ans=max(ans, *min_element(nums.begin()+i, nums.begin()+j+1)*(j-i+1));
	    }
	    return ans;
	}
	*/
};