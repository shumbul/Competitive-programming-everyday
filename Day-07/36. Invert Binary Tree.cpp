// Link - https://leetcode.com/problems/invert-binary-tree/
// Author - Shumbul Arifa

class Solution {
	void invert(TreeNode* root) {
		if (!root)
			return;
		if (root->left && root->right) {
			swap(root->left, root->right);
			invert(root->right);
			invert(root->left);
		}
		else if (root->left) {
			root->right = root->left, root->left = NULL;
			invert(root->right);
		}
		else if (root->right) {
			root->left = root->right, root->right = NULL;
			invert(root->left);
		}
	}
public:
	TreeNode* invertTree(TreeNode* root) {
		invert(root);
		return root;
	}
};