// Link - https://leetcode.com/problems/construct-string-from-binary-tree/
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
	void preorder(TreeNode* root, string &s) {
		if (!root) {
			return;
		}
		s += to_string(root->val);
		if (!root->left && !root->right)
			return;
		s += "(";
		if (root->left) {
			preorder(root->left, s);
		}
		s += ")";
		if (!root->right)
			return;
		s += "(";
		if (root->right) {
			preorder(root->right, s);
		}
		s += ")";
	}
public:
	string tree2str(TreeNode* root) {
		string s;
		if (!root)
			return s;
		preorder(root, s);
		return s;
	}
};