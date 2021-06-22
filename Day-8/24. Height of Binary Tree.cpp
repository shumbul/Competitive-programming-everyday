// Link - https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
// Author - Shumbul Arifa

class Solution {
	int h;
	void solve(struct Node* node, int level) {
		if (!node)
			return;
		h = max(h, level);
		if (node->left)
			solve(node->left, level + 1);
		if (node->right)
			solve(node->right, level + 1);
	}
public:
	//Function to find the height of a binary tree.
	int height(struct Node* node) {
		// code here
		h = 0;
		solve(node, 1);
		return h;
	}
};