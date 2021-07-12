// Link - https://leetcode.com/problems/balanced-binary-tree/
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
	int height(TreeNode* root) {
		if (!root)
			return 0;
		return max(height(root->left), height(root->right)) + 1;
	}
public:
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		return (abs(leftHeight - rightHeight) < 2) && isBalanced(root->right) && isBalanced(root->left);
	}
};