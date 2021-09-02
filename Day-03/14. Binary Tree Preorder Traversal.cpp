// Link - https://leetcode.com/problems/binary-tree-preorder-traversal/
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

// using stacks
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		if (!root)
			return v;
		// NLR
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			auto top = st.top();
			v.push_back(top->val);
			st.pop();
			if (top->right)
				st.push(top->right);
			if (top->left)
				st.push(top->left);
		}
		return v;
	}
};

// using recursion
class Solution {
	vector<int> ans;
	void solve(TreeNode* root) {
		if (!root)
			return;
		ans.push_back(root->val);
		solve(root->left);
		solve(root->right);
	}
public:
	vector<int> preorderTraversal(TreeNode* root) {
		ans.clear();
		solve(root);
		return ans;
	}
};