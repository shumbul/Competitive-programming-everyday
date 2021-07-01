// Link - https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=trees
// Author - Shumbul Arifa

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
void checkBST(Node* root, int llim, int rlim, bool &ans) {
	if (!ans || !root)
		return;
	int r = root->data;
	if (r >= rlim || r <= llim) {
		ans = false;
		return;
	}
	if (root->left) {
		checkBST(root->left, llim, r, ans);
	}
	if (root->right) {
		checkBST(root->right, r, rlim, ans);
	}
}
bool checkBST(Node* root) {
	if (!root)
		return true;
	bool ans = true;
	checkBST(root, -1, 10005, ans);
	return ans;
}