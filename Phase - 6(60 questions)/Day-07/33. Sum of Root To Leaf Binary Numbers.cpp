// Link - https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Author - Shumbul Arifa

class Solution {
	int ans;
	void solve(TreeNode* root, int num) {
		if (!root)
			return;
		num = (num << 1 | root->val); // left shift and bitwise OR
		// if leaf
		if (!root->left && !root->right) {
			ans += num;
		}
		else {
			solve(root->left, num);
			solve(root->right, num);
		}
	}
public:
	int sumRootToLeaf(TreeNode* root) {
		ans = 0;
		solve(root, 0);
		return ans;
	}
};