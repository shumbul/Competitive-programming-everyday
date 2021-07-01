// Link - https://binarysearch.com/problems/First-to-Count-to-Target
// Author - Shumbul Arifa

bool solve(int k, int target) {
	// To not let our opponent win,
	// 1<= X mod(k+1)<=k
	if (target % (k + 1) == 0)
		return false;
	return true;
}