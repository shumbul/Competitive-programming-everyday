// Link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
	int i = 0;
public:
	TreeNode* bstFromPreorder(vector<int>& preorder, int bound = INT_MAX) {
		if (i == preorder.size() || preorder[i] > bound)
			return NULL;
		TreeNode *root = new TreeNode(preorder[i++]);
		root->left = bstFromPreorder(preorder, root->val);
		root->right = bstFromPreorder(preorder, bound);
		return root;
	}
};