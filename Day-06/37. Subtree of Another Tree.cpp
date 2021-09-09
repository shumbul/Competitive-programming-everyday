// Link - https://leetcode.com/problems/subtree-of-another-tree/
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
	bool isSame(TreeNode* root, TreeNode* subRoot) {
		if (!root && !subRoot)
			return true;
		if (!root || !subRoot)
			return false;
		if (root->val != subRoot->val)
			return false;
		return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
	}
public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (!root && subRoot)
			return false;
		if (isSame(root, subRoot))
			return true;
		return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
	}

};