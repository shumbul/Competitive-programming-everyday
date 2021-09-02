// Link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
	TreeNode* solve(int start, int end, vector<int>& nums) {
		if (start > end)
			return nullptr;
		int mid = (end - start) / 2 + start;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = solve(start, mid - 1, nums);
		root->right = solve(mid + 1, end, nums);
		return root;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return solve(0, nums.size() - 1, nums);
	}
};