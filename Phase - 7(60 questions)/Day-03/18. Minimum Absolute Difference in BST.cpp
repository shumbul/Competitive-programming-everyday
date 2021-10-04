// Link - https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
	int val = -1, diff = INT_MAX;
public:
	int getMinimumDifference(TreeNode* root) {
		if (!root)
			return diff;
		if (root->left)
			getMinimumDifference(root->left);
		if (val >= 0) {
			diff = min(diff, abs(root->val - val));
		}
		val = root->val;
		if (root->right)
			getMinimumDifference(root->right);
		return diff;
	}
};