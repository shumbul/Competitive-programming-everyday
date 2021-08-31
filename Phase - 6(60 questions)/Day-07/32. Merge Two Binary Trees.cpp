// Link - https://leetcode.com/problems/merge-two-binary-trees/
// Author - Shumbul Arifa

* /
class Solution {
	TreeNode* Root;
	void merge(TreeNode* root, TreeNode* r1, TreeNode* r2) {
		if (!r1 && !r2)
			return;
		if (r1)
			root->val = root->val + r1->val;
		if (r2)
			root->val = root->val + r2->val;
		if (r1 && r1->left || r2 && r2->left)
			root->left = new TreeNode();
		if (r1 && r1->right || r2 && r2->right)
			root->right = new TreeNode();
		merge(root->left, r1 ? (r1->left) : nullptr, r2 ? (r2->left) : nullptr);
		merge(root->right, r1 ? (r1->right) : nullptr, r2 ? (r2->right) : nullptr);
		return;
		if (r1 && r2) {
			root->left = new TreeNode(r1->val);
			root->right = new TreeNode(r2->val);
			merge(root->left, r1->left, r2->left);
			merge(root->right, r1->right, r2->right);
		}
		else if (r1) {
			root->left = new TreeNode(r1->val);
			merge(root->left, r1->left, nullptr);
		}
		else if (r2) {
			root->right = new TreeNode(r2->val);
			merge(root->right, nullptr, r2->right);
		}
	}
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		TreeNode* root;
		if (!root1 && !root2)
			return root;
		root = new TreeNode();
		Root = root;
		merge(root, root1, root2);
		return Root;
	}
};