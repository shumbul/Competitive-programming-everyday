// Link - https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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
	void inorder(TreeNode* root, vector<int> &l) {
		if (!root)
			return;
		inorder(root->left, l);
		l.push_back(root->val);
		inorder(root->right, l);
	}
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> l1, l2;
		inorder(root1, l1);
		inorder(root2, l2);
		vector<int> ans;
		// merge the lists
		int i = 0, j = 0;
		while (i < l1.size() && j < l2.size()) {
			if (l1[i] < l2[j])
				ans.push_back(l1[i++]);
			else
				ans.push_back(l2[j++]);
		}
		while (i < l1.size())
			ans.push_back(l1[i++]);
		while (j < l2.size())
			ans.push_back(l2[j++]);
		return ans;
	}
};