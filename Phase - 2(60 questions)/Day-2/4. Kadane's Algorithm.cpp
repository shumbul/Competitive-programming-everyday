// Link - https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// Author - Shumbul Arifa

// arr: input array
// n: size of array
//Function to find the sum of contiguous subarray with maximum sum.
int maxSubarraySum(int arr[], int n) {

	// Your code here
	int meh = 0, msf = INT_MIN;
	// max ending here, and max so far
	for (int i = 0; i < n; i++) {
		meh = meh + arr[i];
		if (msf < meh)
			msf = meh;
		if (meh < 0)
			meh = 0;
	}
	return msf;
}