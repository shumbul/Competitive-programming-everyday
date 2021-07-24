// Link - https://leetcode.com/problems/house-robber-iii/
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
	vector<int> rob_(TreeNode* root) {
		vector<int> res(2, 0);
		if (!root)
			return res;
		auto l = rob_(root->left);
		auto r = rob_(root->right);
		res[0] = max(l[0], l[1]) + max(r[0], r[1]); // exclude
		res[1] = root->val + l[0] + r[0];
		return res;
	}
public:
	int rob(TreeNode* root) {
		auto res = rob_(root);
		return max(res[0], res[1]);
	}
};