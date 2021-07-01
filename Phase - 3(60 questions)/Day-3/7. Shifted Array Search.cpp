// Link -https://www.pramp.com/challenge/N5LYMbYzyOtbpovQoYPX
// Author - Shumbul Arifa

int shiftedArrSearch( const vector<int>& A, int num )
{
	// your code goes here
	int l = 0, h = A.size() - 1, mid;
	while (l <= h) {
		mid = ((h - l) / 2 + l);
		if (A[mid] == num) return mid;
		if (A[l] == num) return l;
		if (A[h] == num) return h;
		if (A[mid] > A[h] && A[mid] > num)
			l = mid + 1; // shifted
		else if (A[mid] > A[h] && A[mid] < num)
			h = mid - 1; // shifted but val is in the left part
		else {
			// unshifted
			if (A[mid] < num)
				l = mid + 1;
			else
				h = mid - 1;
		}
	}
	return -1;
}