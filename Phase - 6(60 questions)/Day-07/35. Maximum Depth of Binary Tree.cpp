// Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author - Shumbul Arifa

class Solution {
	int depth;
	void dfs(TreeNode* root, int d) {
		if (!root)
			return;
		depth = max(d, depth);
		if (root->left)
			dfs(root->left, d + 1);
		if (root->right)
			dfs(root->right, d + 1);
	}
public:
	int maxDepth(TreeNode* root) {
		depth = 0;
		dfs(root, 1);
		return depth;
	}
};