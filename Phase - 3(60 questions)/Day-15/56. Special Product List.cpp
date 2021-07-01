// Link - https://binarysearch.com/problems/Special-Product-List
// Author - Shumbul Arifa

vector<int> solve(vector<int>& nums) {
	int n = nums.size();
	vector<int> l2r(n + 1, 1), r2l(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		l2r[i] = l2r[i - 1] * nums[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		r2l[i] = r2l[i + 1] * nums[i];
	}
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		ans[i] = l2r[i] * r2l[i + 1];
	return ans;
}