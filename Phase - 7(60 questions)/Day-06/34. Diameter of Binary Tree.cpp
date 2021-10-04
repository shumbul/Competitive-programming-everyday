// Link - https://leetcode.com/problems/diameter-of-binary-tree/
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
	int solve(TreeNode* root, int &h) {
		if (!root) {
			h = 0; return 0;
		}
		int lh = 0, rh = 0, ld = 0, rd = 0;
		ld = solve(root->left, lh);
		rd = solve(root->right, rh);
		h = max(lh, rh) + 1;
		return max({lh + rh + 1, ld, rd});
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;
		int h = 0;
		return solve(root, h) - 1;
	}
};

// using height
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
	int maxdia(TreeNode* root) {
		// dia = maxdepth of left child + maxdepth of right child
		if (!root)
			return 0;
		return 1 + max(maxdia(root->left), maxdia(root->right));
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;
		int curr = maxdia(root->left) + maxdia(root->right);
		int l = diameterOfBinaryTree(root->left);
		int r = diameterOfBinaryTree(root->right);
		return max({curr, l, r});
	}
};