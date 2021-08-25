// Link - https://leetcode.com/problems/average-of-levels-in-binary-tree/
// Author - Shumbul Arifa

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		// bfs
		vector<double> ans;
		vector<double> lvl[10001];
		if (!root)
			return ans;
		queue<TreeNode* > q;
		q.push(root);
		int l = 0;
		// lvl[l++].push_back(root->val);
		while (!q.empty()) {
			int s = q.size();
			while (s--) {
				auto a = q.front();
				q.pop();
				if (a->left)
					q.push(a->left);
				if (a->right)
					q.push(a->right);
				lvl[l].push_back(a->val);
			}
			l++;
		}
		for (int i = 0; i < l; i++) {
			double d = 0;
			for (double j : lvl[i])
				d += j;
			ans.push_back(d * 1.0 / lvl[i].size());
		}
		return ans;
	}
};