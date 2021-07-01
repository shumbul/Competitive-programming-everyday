// Link - https://www.interviewbit.com/old/problems/2sum-binary-tree/
// Author - Shumbul Arifa

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool search(TreeNode* root, TreeNode* curr, int B) {
	if (root == NULL)
		return false;
	return (root != curr && root->val == B) ||
	       (root->val <= B && search(root->right, curr, B)) ||
	       (root->val >= B && search(root->left, curr, B));
}
bool dfs(TreeNode* root, TreeNode* curr, int B) {
	if (!curr)
		return false;
	return dfs(root, curr->left, B) || dfs(root, curr->right, B) || search(root, curr, B - curr->val);
}
int Solution::t2Sum(TreeNode* A, int B) {
	return dfs(A, A, B);
}
