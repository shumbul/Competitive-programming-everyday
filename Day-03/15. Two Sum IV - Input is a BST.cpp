// Link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
	TreeNode* R;
	void bins(TreeNode* root, TreeNode* node, int k) {
		if (!node || ans)
			return;
		// cout<<root->val<<" "<<node->val<<" "<<k<<"\n";
		if (root != node && node->val == k) {
			ans = true;
			return;
		}
		if (node->left && k < node->val)
			bins(root, node->left, k);
		else if (node->right && k > node->val)
			bins(root, node->right, k);
	}
	void inorder(TreeNode* root, int k) {
		if (!root || ans)
			return;
		bins(root, R, k - root->val);
		if (root->left)
			inorder(root->left, k);
		if (root->right)
			inorder(root->right, k);
	}
public:
	bool findTarget(TreeNode* root, int k) {
		ans = false;
		R = root;
		if (!root)
			return ans;
		inorder(root, k);
		return ans;
	}
};