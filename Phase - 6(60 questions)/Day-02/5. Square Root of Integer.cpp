// Link - https://www.interviewbit.com/old/problems/square-root-of-integer/
// Author - Shumbul Arifa

int Solution::sqrt(int A) {
	if (A == 0)    return 0;
	int start = 1, end = A, ans = 1, mid;
	while (start <= end) {
		mid = (end - start) / 2 + start;
		// cout<<end<<" "<<start<<" "<<mid<<" -> ";
		assert(mid != 0);
		if (mid == A / mid)
			return mid;
		if (mid < A / mid)
			ans = mid, start = mid + 1;
		else
			end = mid - 1;
	}
	return ans;
}
