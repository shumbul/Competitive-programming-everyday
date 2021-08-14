// Link - https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
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
	TreeNode* recoverFromPreorder(string S) {
		// if more number of dots -> left child of node
		// if same number of dots -> right child of node
		// if less number of dots -> right child of node's parent at that level
		stack<TreeNode* > st;
		int i = 0, n = S.length(), level = 0, num = 0;
		while (i < n) {
			for (level = 0; S[i] == '-'; level++, i++);
			num = 0;
			while (i < n && S[i] != '-')
				num = num * 10 + (S[i] - '0'), i++;
			while (st.size() > level)  st.pop();
			TreeNode* tmp = new TreeNode(num);
			if (!st.empty() && !st.top()->left)
				st.top()->left = tmp;
			else if (!st.empty())
				st.top()->right = tmp;
			st.push(tmp);
		}
		while (st.size() > 1)
			st.pop();
		return st.empty() ? NULL : st.top();
	}
};