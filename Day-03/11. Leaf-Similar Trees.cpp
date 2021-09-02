// Link - https://leetcode.com/problems/leaf-similar-trees/
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

// Using controlled DFS
class Solution {
	int controlledDFS(stack<TreeNode*> &st) {
		while (st.size()) {
			auto a = st.top();
			st.pop();
			if (!a->left && !a->right)
				return a->val;
			if (a->left) st.push(a->left);
			if (a->right) st.push(a->right);
		}
		return 0;
	}
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		stack<TreeNode*> s1, s2;
		s1.push(root1);
		s2.push(root2);
		while (!s1.empty() && !s2.empty()) {
			if (controlledDFS(s1) != controlledDFS(s2))
				return false;
		}
		return s1.empty() && s2.empty();
	}
};

// Naive method
class Solution {
	void complete(TreeNode* root, vector<int> &l) {
		if (!root)
			return;
		if (!root->right && !root->left)
			l.push_back(root->val);
		if (root->left)
			complete(root->left, l);
		if (root->right)
			complete(root->right, l);
	}
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> l1, l2;
		complete(root1, l1);
		complete(root2, l2);
		return l1 == l2;
	}
};