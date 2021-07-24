// Link - https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
// Author - Shumbul Arifa

long long countTriplets(long long arr[], int n, long long sum)
{
	// Your code goes here
	int ans = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; i++) {
		int j = i + 1, k = n - 1;
		while (j < k) {
			if (arr[i] + arr[j] + arr[k] >= sum)
				k--;
			else {
				ans += (k - j); // important, reason: there can be (k-j) third elements
				j++;
			}
		}
	}
	return ans;
}