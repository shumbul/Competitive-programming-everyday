// Link - https://leetcode.com/problems/binary-tree-inorder-traversal
// Author - Shumbul Arifa

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> ans;
    void inorder(TreeNode* root){
        if(!root)
            return;
        if(root->left)
            inorder(root->left);
        ans.push_back(root->val);
        if(root->right)
            inorder(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        inorder(root);
        return ans;
    }
};
