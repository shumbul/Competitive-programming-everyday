// Link - https://leetcode.com/problems/generate-parentheses
// Author - Shumbul Arifa

class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        solve(n, "", 0, 0);
        return ans;
    }
    void solve(int n, string s, int open, int close) {
        if(s.length()==2*n) {
            ans.push_back(s);
            return;
        }
        if(open<n)
            solve(n, s+"(", open+1, close);
        if(close<open)
            solve(n, s+")", open, close+1);
    }
};
