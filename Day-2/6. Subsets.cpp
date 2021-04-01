// Link - https://leetcode.com/problems/subsets/
// Author - Shumbul Arifa

/* ########## M-1 Cascading ########## */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        ans.push_back({});
        
        for(int num: nums) {
            vector<vector<int>> newsub;
            vector<int> thissub;
            for(auto old:ans) {
                thissub=old;
                thissub.push_back(num);
                newsub.push_back(thissub);
            }
            for(auto a:newsub) {
                ans.push_back(a);
            }
        }
        return ans;
    }
};

/* ########## M-2 Backtracking ########## */

class Solution {
    vector<vector<int>> ans;
    int k;
    void backtrack(vector<int> &nums, int first, vector<int> curr) {
        if(curr.size()==k) {
            ans.push_back(curr);
        }
        for(int i=first;i<nums.size();i++) {
            curr.push_back(nums[i]);
            backtrack(nums, i+1, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> curr;
        for(k=0;k<nums.size()+1;k++){
            curr={};
            backtrack(nums, 0, curr);
        }
        return ans;
    }
};