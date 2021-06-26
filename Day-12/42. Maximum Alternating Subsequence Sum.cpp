// Link - https://leetcode.com/contest/biweekly-contest-55/problems/maximum-alternating-subsequence-sum/
// Author - Shumbul Arifa

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = 0, odd = 0;
        for (auto a : nums) {
            long long new_even = max(even, odd - a);
            odd = max(odd, even + a);
            even = new_even;
        }
        return max(even, odd);
    }
};