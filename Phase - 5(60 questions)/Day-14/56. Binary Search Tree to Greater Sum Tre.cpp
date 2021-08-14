// Link - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
	int sum;
	void solve(TreeNode* root) {
		if (!root)
			return;
		solve(root->right);
		sum += root->val;
		root->val = sum;
		solve(root->left);
	}
public:
	TreeNode* bstToGst(TreeNode* root) {
		sum = 0;
		solve(root);
		return root;
	}
};