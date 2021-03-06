// Link - https://leetcode.com/problems/permutations
// Author - Shumbul Arifa

class Solution {
    vector<vector<int>> ans;
    
    void solve(vector<int>&vec, int s){
        int n=vec.size();
        if(s==n){
            ans.push_back(vec);
        }
        for(int i=s;i<n;i++){
            swap(vec[i], vec[s]);
            solve(vec, s+1);
            swap(vec[i], vec[s]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // recursion
        ans.clear();
        auto vec=nums;
        solve(nums, 0);
        return ans;   
    }
};
