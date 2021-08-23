// Link - https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Author - Shumbul Arifa

class Solution {
	vector<int> ans;
	void solve(Node* root) {
		if (!root)
			return;
		ans.push_back(root->val);
		if (root->children.size() > 0) {
			for (auto a : root->children)
				solve(a);
		}
	}
public:
	vector<int> preorder(Node* root) {
		ans.clear();
		solve(root);
		return ans;
	}
};