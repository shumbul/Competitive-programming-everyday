// Link - https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
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
#include<bits/stdc++.h>
int ans;
void solve_(TreeNode* A, int& B) {
	if (!A)
		return;
	if (B < 1)
		return;
	if (A->left) {
		solve_(A->left, B);
		B--;
	}
	if (B == 1) {
		ans = A->val;
		return;
	}
	if (A->right) {
		solve_(A->right, --B);
	}
}
int Solution::kthsmallest(TreeNode* A, int B) {
	solve_(A, B);
	return ans;
}

