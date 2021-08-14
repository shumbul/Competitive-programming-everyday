// Link - https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
	int ans;
	void solve(TreeNode* root) {
		if (!root)
			return;
		if (root->val % 2 == 0) {
			// add grandchildren if any
			if (root->left) {
				if (root->left->left)
					ans += root->left->left->val;
				if (root->left->right)
					ans += root->left->right->val;
			}
			if (root->right) {
				if (root->right->left)
					ans += root->right->left->val;
				if (root->right->right)
					ans += root->right->right->val;
			}
		}
		solve(root->left);
		solve(root->right);
	}
public:
	int sumEvenGrandparent(TreeNode* root) {
		ans = 0;
		solve(root);
		return ans;
	}
};