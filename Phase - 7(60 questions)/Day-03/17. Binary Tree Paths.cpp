// Link - https://leetcode.com/problems/binary-tree-paths/
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
	vector<string> ans;
	void solve(TreeNode* root, string s) {
		if (!root)
			return;
		if (!root->left && !root->right) {
			s += to_string(root->val);
			ans.push_back(s);
			return;
		}
		string t = s;
		t += to_string(root->val);
		if (root->left) {
			string l = t;
			t += "->";
			solve(root->left, t);
			if (l + "->" == t)
				t = l;
		}
		if (root->right) {
			string l = t;
			t += "->";
			solve(root->right, t);
			if (l + "->" == t)
				t = l;
		}
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		ans.clear();
		if (!root)
			return ans;
		string s;
		solve(root, s);
		return ans;
	}
};