// Link - https://www.interviewbit.com/old/problems/first-index/?ref=similar_problems
// Author - Shumbul Arifa

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
	// brute force
	int n = B.size();
	map<int, int> mp;
	vector<int> ans(n, -1);
	for (int q = 0; q < n; q++) {
		if (mp.find(B[q]) != mp.end()) {
			ans[q] = mp[B[q]];
			continue;
		}
		for (int x = 0; x < A.size(); x++) {
			if (A[x] >= B[q]) {
				ans[q] = x;
				mp[B[q]] = x;
				break;
			}
		}
	}
	return ans;
}
