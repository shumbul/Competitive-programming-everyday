// Link - https://leetcode.com/problems/maximum-subarray/
// Author - Shumbul Arifa

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's algorithm
        int curr = -100001, maxi = curr;
        for (auto i : nums) {
            curr = max(i, curr + i); // whether to start fresh, or add in prev
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};