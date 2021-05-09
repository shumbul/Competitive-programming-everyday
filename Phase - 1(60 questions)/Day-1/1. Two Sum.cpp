// Link - https://leetcode.com/problems/two-sum
// Author - Shumbul Arifa

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> mp;
        int i=0;
        for(auto a:nums)
            mp[a]=i++;
        i=0;
        for(auto a:nums){
            if(mp.find(target-a)!=mp.end() && mp[target-a]!=i){
                ans.push_back(i);
                ans.push_back(mp[target-a]);
                return ans;
            }
            i++;
        }
        return ans;
    }
};
