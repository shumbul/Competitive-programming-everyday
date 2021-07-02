// Link - https://www.geeksforgeeks.org/find-maximum-sum-triplets-array-j-k-ai-aj-ak/
// Author - Shumbul Arifa

// return the triplet indices, follow lexicpgraphically smaller one for decision
vector<int> maximumSumTriplet(vector<int> ar, int n) {
	int ans = 0, t1 = 0, t2 = 0;
	vector<int> trips(3, -1);
	for (int i = 1; i < n - 1; i++) {
		int max_before = 0, max_after = 0;
		for (int j = 0; j < i; j++) {
			if (ar[i] > ar[j]) {
				if (max_before < ar[j]) {
					t1 = j;
					max_before = ar[j];
				}
			}
		}
		for (int k = i + 1; k < n; k++) {
			if (ar[k] > ar[i]) {
				if (max_after < ar[k]) {
					t2 = k;
					max_after = ar[k];
				}
			}
		}
		if (max_after && max_before) {
			if (ans < max_after + max_before + ar[i]) {
				trips[0] = i, trips[1] = t1, trips[2] = t2;
				ans = max_after + max_before + ar[i];
			}
		}
	}
	return trips;
}