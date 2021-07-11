// Link - https://www.interviewbit.com/old/problems/least-common-ancestor/
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

bool findPathRootToNode(TreeNode* A, int B, vector<int>& v) {
	if (!A)
		return false;
	v.push_back(A->val);
	if (A->val == B)
		return true;

	if (findPathRootToNode(A->left, B, v) || findPathRootToNode(A->right, B, v))
		return true;

	v.pop_back();
	return false;
}

int Solution::lca(TreeNode* A, int B, int C) {
	// 1. Find paths to each
	vector<int> p1;
	bool b1 = findPathRootToNode(A, B, p1);
	vector<int> p2;
	bool b2 = findPathRootToNode(A, C, p2);
	// for(auto a:p1)
	//     cout<<a<<" ";
	// cout<<" -> ";
	// for(auto a:p2)
	//     cout<<a<<" ";
	// cout<<" -> ";
	// 2. Paths should exist for both, otherwise return -1
	if (!b1 || !b2)
		return -1;
	// 3. traverse in path from root to them until they are both following the same path
	int i = 0;
	while (i < p1.size() && i < p2.size() && (p1[i] == p2[i]))
		i++;
	i--;
	return i < 0 ? -1 : p1[i];
}
