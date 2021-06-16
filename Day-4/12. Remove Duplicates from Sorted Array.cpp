// Link - https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
// Author - Shumbul Arifa

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int removeDuplicates(int* A, int n1) {
	if (n1 < 2)
		return n1;
	int i, count = 0, j;
	int k = n1;
	for (i = 1; i < n1; i++)
	{
		if (A[i] != A[count])
			A[++count] = A[i];
	}
	return count + 1;
}
