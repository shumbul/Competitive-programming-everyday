// Link - https://leetcode.com/problems/maximum-binary-tree/
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
	TreeNode *root;
	TreeNode *solve(TreeNode *node, vector<int>& nums, int l, int r) {
		if (l >= r)
			return nullptr;
		auto it_max = max_element(nums.begin() + l, nums.begin() + r);
		node = new TreeNode(*it_max);
		node->left = solve(node->left, nums, l, it_max - nums.begin());
		node->right = solve(node->right, nums, it_max - nums.begin() + 1, r);
		return node;
	}
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.empty())
			return root;
		auto it_max = max_element(nums.begin(), nums.end());
		root = new TreeNode(*it_max);
		root->left = solve(root->left, nums, 0, it_max - nums.begin());
		root->right = solve(root->right, nums, it_max - nums.begin() + 1, nums.size());
		return root;
	}
};