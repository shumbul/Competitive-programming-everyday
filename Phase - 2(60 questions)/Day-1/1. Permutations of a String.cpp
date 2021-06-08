// Link - https://practice.geeksforgeeks.org/problems/permutations-of-a-string/1/?track=md-backtracking&batchId=144
// Author - Shumbul Arifa

class Solution {
  vector<string> ans;
  void solve(string s, int b) {
    if (b == s.length() - 1)
      ans.push_back(s);
    for (int i = b; i < s.length(); i++) {
      swap(s[i], s[b]);
      solve(s, b + 1);
      swap(s[i], s[b]);
    }
  }
public:
  vector<string> permute(string s) {
    // code here
    ans.clear();
    solve(s, 0);
    return ans;
  }
};