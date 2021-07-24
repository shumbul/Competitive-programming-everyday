// Link - https://www.interviewbit.com/old/problems/rotated-sorted-array-search/
// Author - Shumbul Arifa

int bin_search(const vector<int> &A, int B, int l, int h) {
	int n = A.size();
	if (n == 0)
		return -1;
	int mid;
	while (l <= h) {
		mid = l + (h - l) / 2;
		if (A[mid] == B)
			return mid;
		if (A[mid] < B) {
			l = mid + 1;
		}
		else
			h = mid - 1;
	}
	return -1;
}
int Solution::search(const vector<int> &A, int B) {
	int n = A.size();
	if (n == 0)
		return -1;

	int l, h, mid;
	l = 0, h = n - 1;
	while (l < h) {
		mid = l + (h - l) / 2;
		if (A[mid] == B)
			return mid;
		if (A[mid] > A[h]) {
			l = mid + 1;
		}
		else
			h = mid;
	}
	if (B <= A[n - 1])
		return bin_search(A, B, l, n - 1);
	return bin_search(A, B, 0, l - 1);
}
