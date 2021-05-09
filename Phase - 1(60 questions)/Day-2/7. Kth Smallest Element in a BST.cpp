// Link - https://leetcode.com/problems/kth-smallest-element-in-a-bst
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
	int ans, i, k;

	void inorder(TreeNode* root) {
		if (!root || i > k)
			return;
		if (root->left)
			inorder(root->left);
		i++;
		if (i == k) {
			ans = root->val;
			return;
		}
		if (root->right)
			inorder(root->right);
	}
public:
	int kthSmallest(TreeNode* root, int K) {
		i = 0, k = K;
		inorder(root);
		return ans;
	}
};