// Link - https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Author - Shumbul Arifa

class Solution {
	int depth;
	void dfs(Node* root, int d) {
		if (!root)
			return;
		depth = max(d, depth);
		for (auto a : root->children)
			dfs(a, d + 1);
	}
public:
	int maxDepth(Node* root) {
		depth = 0;
		// dfs twice
		dfs(root, 1);
		return depth;
	}
};