// Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Author - Shumbul Arifa

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return root;
		if (root->val == p->val || root->val == q->val)
			return root;
		if (root->val > max(p->val, q->val))
			return lowestCommonAncestor(root->left, p, q);
		else if (root->val < min(p->val, q->val))
			return lowestCommonAncestor(root->right, p, q);
		return root;
	}
};