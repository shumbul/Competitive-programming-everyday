// Link - https://practice.geeksforgeeks.org/problems/mirror-tree/1#
// Author - Shumbul Arifa

class Solution {
public:
	// Function to convert a binary tree into its mirror tree.
	void mirror(Node* node) {
		// code here
		if (!node)
			return;
		auto tmpl = node->left;
		auto tmpr = node->right;
		node->left = tmpr, node->right = tmpl;
		if (node->left)
			mirror(node->left);
		if (node->right)
			mirror(node->right);
	}
};