// Link - https://www.interviewbit.com/old/problems/container-with-most-water/
// Author - Shumbul Arifa

int Solution::maxArea(vector<int> &A) {
	int ans = 0;
	int low = 0, high = A.size() - 1;
	while (low <= high) {
		ans = max(ans, (high - low) * min(A[low], A[high]));
		if (A[high] >= A[low]) {
			low++;
		}
		else {
			high--;
		}
	}
	return ans;
}
