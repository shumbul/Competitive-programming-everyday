// Link - https://leetcode.com/problems/range-sum-of-bst/
// Author - Shumbul Arifa

// 1
class Solution {
public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		if (!root)
			return 0;
		else if (root->val > high)
			return rangeSumBST(root->left, low, high);
		else if (root->val < low)
			return rangeSumBST(root->right, low, high);
		return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
	}
};

// 2
class Solution {
	int ans = 0;
	void solve(TreeNode* root, int low, int high) {
		if (!root)
			return;
		if (root->val >= low && root->val <= high)
			ans += root->val;
		if (root->val < low)
			solve(root->right, low, high);
		else if (root->val > high)
			solve(root->left, low, high);
		else {
			solve(root->right, low, high);
			solve(root->left, low, high);
		}
	}
public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		// no overlap, complete overlap, partial overlap
		solve(root, low, high);
		return ans;
	}
};