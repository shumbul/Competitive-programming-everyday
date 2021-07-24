// Link - https://leetcode.com/problems/binary-tree-postorder-traversal/
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
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root)
			return {};
		// LNR
		stack<TreeNode*> st;
		st.push(root);
		vector<int> ans;
		while (!st.empty()) {
			auto top = st.top();
			ans.insert(ans.begin(), top->val);
			st.pop();
			if (top->left)
				st.push(top->left);
			if (top->right)
				st.push(top->right);

		}
		return ans;
	}
};


// M-2: recursion

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
	vector<int> ans;
	void solve(TreeNode* root) {
		if (!root)
			return;
		solve(root->left);
		ans.push_back(root->val);
		solve(root->right);
	}
public:
	vector<int> preorderTraversal(TreeNode* root) {
		ans.clear();
		solve(root);
		return ans;
	}
};