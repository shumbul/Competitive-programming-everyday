// Link - https://leetcode.com/problems/cousins-in-binary-tree/
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
	bool ans = false;
	int HX = INT_MIN, HY = INT_MAX;
	TreeNode* parx, *pary;
	void solve(TreeNode* par, TreeNode* root, int x, int y, int h) {
		if (!root)
			return;
		// cout<<root->val<<" & "<<x<<" "<<y<<" -> "<<h<<"\n";
		if (root->val == x)
			HX = h, parx = par;
		else if (root->val == y)
			HY = h, pary = par;
		solve(root, root->left, x, y, h + 1);
		solve(root, root->right, x, y, h + 1);
	}
public:
	bool isCousins(TreeNode* root, int x, int y) {
		int h = 0;
		HX = INT_MIN, HY = INT_MAX;
		parx = pary = nullptr;
		solve(nullptr, root, x, y, h);
		// cout<<(HX==HY)<<" "<<(parx!=pary)<<"\n";
		return HX == HY && (parx != pary);
	}
};