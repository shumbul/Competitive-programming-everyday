// Link - https://leetcode.com/problems/sum-of-left-leaves/
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
	int sumi;
	void solve(TreeNode* root, bool isleft) {
		if (!root)
			return;
		if (isleft && !root->left && !root->right) {
			sumi += root->val;
			return;
		}
		if (root->left)
			solve(root->left, true);
		if (root->right)
			solve(root->right, false);
	}
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)
			return 0;
		sumi = 0;
		solve(root, false);
		return sumi;
	}
};