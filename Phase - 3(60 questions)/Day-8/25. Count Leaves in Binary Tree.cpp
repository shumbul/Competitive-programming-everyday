// Link - https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1
// Author - Shumbul Arifa

int ans;
void solve(Node* root) {
	if (!root)
		return;
	if (!root->left && !root->right)
		ans++;
	if (root->left)
		solve(root->left);
	if (root->right)
		solve(root->right);
}
int countLeaves(Node* root)
{
	ans = 0;
	// Your code here
	solve(root);
	return ans;
}