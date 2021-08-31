// Link - https://leetcode.com/problems/univalued-binary-tree/
// Author - Shumbul Arifa

class Solution {
	bool ans = 1;
	int val;
	void solve(TreeNode* root) {
		if (!root || !ans)
			return;
		if (root->val != val) {
			ans = 0; return;
		}
		solve(root->left);
		solve(root->right);
	}
public:
	bool isUnivalTree(TreeNode* root) {
		ans = true;
		if (!root)
			return ans;
		val = root->val;
		solve(root);
		return ans;
	}
};