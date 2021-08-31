// Link - https://leetcode.com/problems/increasing-order-search-tree/
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
	TreeNode* newroot;
	void solve(TreeNode* root) {
		if (!root) {
			return;
		}
		if (root->left)
			solve(root->left);
		newroot->right = root;
		// SET root's left and right to NULL
		root->left = NULL;
		auto x = root->right;
		root->right = NULL;
		newroot->left = NULL;
		newroot = newroot->right;
		if (x)
			solve(x);
	}
public:
	TreeNode* increasingBST(TreeNode* root) {
		// preorder traversal
		newroot = new TreeNode();
		auto hold = newroot;
		solve(root);
		return hold->right;
	}
};