// Link - https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
// Author - Shumbul Arifa

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 *
 * @Return Returns a array of size n1 + n2 with A and B merged.
 */
int* merge(int* A, int n1, int* B, int n2) {
	int i = 0, j = 0, index = 0, n = n1 + n2;
	int *res = (int*)malloc(sizeof(int) * (n1 + n2));
	while (i < n1 && j < n2)
	{
		if (A[i] < B[j])
		{
			res[index++] = A[i++];
		}
		else
		{
			res[index++] = B[j++];
		}
	}
	while (i < n1)
	{
		res[index++] = A[i++];
	}
	while (j < n2)
	{
		res[index++] = B[j++];
	}
	return res;
}
