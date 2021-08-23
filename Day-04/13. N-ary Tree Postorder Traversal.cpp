// Link - https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Author - Shumbul Arifa

class Solution {
	vector<int> ans;
	void solve(Node* root) {
		if (!root)
			return;
		if (root->children.size() > 0) {
			for (auto a : root->children)
				solve(a), ans.push_back(a->val);
		}
	}
public:
	vector<int> postorder(Node* root) {
		ans.clear();
		if (!root)
			return ans;
		solve(root);
		ans.push_back(root->val);
		return ans;
	}
};