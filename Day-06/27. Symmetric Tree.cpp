// Link - https://leetcode.com/problems/symmetric-tree/
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
	bool issym(TreeNode* n1, TreeNode* n2) {
		if (!n1 && !n2)
			return true;
		if (!n1 || !n2)
			return false;
		if (n1->val != n2->val)
			return false;
		return issym(n1->left, n2->right) && issym(n1->right, n2->left);
	}
public:
	bool isSymmetric(TreeNode* root) {
		return issym(root, root);
	}
};