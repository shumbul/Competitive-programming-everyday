// Link - https://leetcode.com/problems/deepest-leaves-sum/
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
	int deepestLeavesSum(TreeNode* root) {
		// bfs
		if (!root)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int ans;
		while (!q.empty()) {
			ans = 0;
			int s = q.size();
			for (int i = 0; i < s; i++) {
				auto b = q.front();
				q.pop();
				if (b->left)
					q.push(b->left);
				if (b->right)
					q.push(b->right);
				ans += b->val;
			}
		}
		return ans;
	}
};