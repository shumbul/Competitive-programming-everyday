// Link - https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3661/
// Author - Shumbul Arifa

/*
* Definition for a binary tree node.
* struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
        *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
        *
    };
*/
class Solution {
    vector<vector<int>> nodes;
    void dfs(TreeNode* root, int d) {
        if (root == nullptr)
            return;
        if (nodes.size() <= d) {
            vector<int> v;
            v.push_back(root->val);
            nodes.push_back(v);
        }
        else nodes[d].push_back(root->val);

        if (root->right)
            dfs(root->right, d + 1);
        if (root->left)
            dfs(root->left, d + 1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        vector<double> ans;
        for (auto a : nodes) {
            double s = accumulate(a.begin(), a.end(), 0.0) / a.size();
            ans.push_back(s);
        }
        return ans;
    }
};