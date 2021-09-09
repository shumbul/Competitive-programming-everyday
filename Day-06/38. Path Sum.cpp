// Link - https://leetcode.com/problems/path-sum/
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
	bool ans;
	void solve(TreeNode* root, int t, int s) {
		if (!root || ans)
			return;
		s += root->val;
		if (root->left)
			solve(root->left, t, s);
		if (root->right)
			solve(root->right, t, s);
		if (!root->left && !root->right) {
			ans = ans || (s == t);
			return;
		}
	}
public:
	bool hasPathSum(TreeNode* root, int targetSum) {

		ans = false;
		solve(root, targetSum, 0);
		return ans;
	}
};