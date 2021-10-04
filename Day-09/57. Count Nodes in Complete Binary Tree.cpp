// Link - https://binarysearch.com/problems/Count-Nodes-in-Complete-Binary-Tree
// Author - Shumbul Arifa

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int d;
void SOL(Tree* root) {
	if (!root)
		return;
	d++;
	if (root && !root->left) {
		return;
	}
	SOL(root->left);
	SOL(root->right);
}
int solve(Tree* root) {
	d = 0;
	SOL(root);
	return d;
}