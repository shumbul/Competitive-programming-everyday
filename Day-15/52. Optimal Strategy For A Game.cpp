// Link - https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1#
// Author - Shumbul Arifa

int F[1001][1001];
int f(int arr[], int i, int j, int sum) {
	if (F[i][j] != -1)
		return F[i][j];
	if (i == j - 1)
		return F[i][j] = max(arr[i], arr[j]);

	return F[i][j] = max(sum - f(arr, i + 1, j, sum - arr[i]), sum - f(arr, i, j - 1, sum - arr[j]));
}

long long maximumAmount(int arr[], int n)
{
	// Your code here
	memset(F, -1, sizeof(F));
	return f(arr, 0, n - 1, accumulate(arr, arr + n, 0));
}