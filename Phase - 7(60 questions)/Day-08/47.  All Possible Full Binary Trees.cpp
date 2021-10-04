// Link - https://leetcode.com/problems/all-possible-full-binary-trees/
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
	map<int, vector<TreeNode*>> dp;
public:
	vector<TreeNode*> allPossibleFBT(int n) {
		if (dp.find(n) != dp.end()) {
			return dp[n];
		}
		if (n == 1)
			return dp[n] = {new TreeNode()};
		vector<TreeNode*> ans;
		for (int i = 1; i < n; i += 2) {
			auto left_tree = allPossibleFBT(i);
			auto right_tree = allPossibleFBT(n - i - 1);
			for (auto left : left_tree) {
				for (auto right : right_tree) {
					TreeNode* root = new TreeNode();
					root->left = left;
					root->right = right;
					ans.push_back(root);
				}
			}
		}
		return dp[n] = ans;
	}
};