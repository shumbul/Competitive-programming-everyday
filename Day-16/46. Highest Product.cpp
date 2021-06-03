// Link - https://www.interviewbit.com/problems/highest-product/
// Author - Shumbul Arifa
// Topic: Greedy

int Solution::maxp3(vector<int> &ar) {
	auto A = ar;
	int n = A.size();
	if (n < 3)
		return -1;
	sort(A.begin(), A.end());
	vector<int> poss;
	poss.push_back(A[0]*A[1]*A[n - 1]);
	poss.push_back(A[n - 1]*A[n - 2]*A[n - 3]);
	return *max_element(poss.begin(), poss.end());
}