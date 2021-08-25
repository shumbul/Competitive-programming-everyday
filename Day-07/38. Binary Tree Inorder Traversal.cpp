// Link - https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author - Shumbul Arifa

class Solution {
	vector<int> ans;
	void inorder(TreeNode* root) {
		if (!root)
			return;
		if (root->left)
			inorder(root->left);
		ans.push_back(root->val);
		if (root->right)
			inorder(root->right);
	}
public:
	vector<int> inorderTraversal(TreeNode* root) {
		ans.clear();
		inorder(root);
		return ans;
	}
};