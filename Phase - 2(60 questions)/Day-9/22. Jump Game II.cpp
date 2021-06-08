// Link - https://leetcode.com/problems/jump-game-ii/
// Author - Shumbul Arifa

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ar1[n];
        ar1[0] = 0;
        for (int i = 1; i < n; i++) { // curr index
            for (int j = 0; j < i; j++) { // index where it may jump from
                if (nums[j] >= i - j) {
                    ar1[i] = ar1[j] + 1; // j is just 1 jump ahead from min num of jumps to reach i
                    break;
                }
            }
        }
        return ar1[n - 1];
    }
};