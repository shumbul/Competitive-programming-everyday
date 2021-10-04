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
		vector<int> ans;
		if (!root)
			return ans;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			auto a = st.top();
			st.pop();
			ans.push_back(a->val);
			if (a->left)
				st.push(a->left);
			if (a->right)
				st.push(a->right);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};