// Link - https://leetcode.com/problems/count-number-of-teams/
// Author - Shumbul Arifa

class bst {
public:
	bst* left, * right;
	int g, s, val;  // greater, smaller
	bst() {
		this->left = nullptr;
		this->right = nullptr;
		this->val = 0;
		this->g = 0;
		this->s = 0;
	}
	bst(int val) {
		this->left = nullptr;
		this->right = nullptr;
		this->val = val;
		this->g = 0;
		this->s = 0;
	}
};
map<int, int> mps, mpg;
bst* insert_bst(int i, bst* root) {
	if (!root)
		return new bst(i);
	if (root->val > i) {
		root->left = insert_bst(i, root->left);
		root->left->g += root->g + 1;
		root->left->s += root->s;
		if (mpg.find(i) == mpg.end()) {
			mpg[i] = root->left->g;
			mps[i] = root->left->s;
		}
		root->s++;
	}
	else if (root->val < i) {
		root->right = insert_bst(i, root->right);
		root->right->s += root->s + 1;
		root->right->g += root->g;
		if (mps.find(i) == mps.end()) {
			mps[i] = root->right->s;
			mpg[i] = root->right->g;
		}
		root->g++;
	}
	return root;
}
class Solution {
	void inorder(bst* root) {
		if (!root)
			return;
		inorder(root->left);
		cout << root->val << " " << mps[root->val] << " " << mpg[root->val] << "\n";
		inorder(root->right);
	}
public:
	int numTeams(vector<int>& rate) {
		int leftinc, leftdec, rightinc, rightdec, res = 0;
		int n = rate.size();
		bst* root = new bst(rate[0]);
		for (int i = 1; i < n; i++) {
			insert_bst(rate[i], root);
		}
		inorder(root);
		auto MPS = mps;
		auto MPG = mpg;
		mps.clear();
		mpg.clear();
		bst* root2 = new bst(rate[n - 1]);
		for (int i = n - 2; i >= 0; i--) {
			insert_bst(rate[i], root2);
		}
		inorder(root2);
		for (int i : rate) {
			res += mps[i] * MPG[i] + MPS[i] * mpg[i];
		}
		return res;
	}
};