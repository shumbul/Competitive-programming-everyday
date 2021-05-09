// Link - https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#
// Author - Shumbul Arifa

class Solution {
public:
	// Function to find the subarray with given sum k
	// arr: input array
	// n: size of array
	vector<int> subarraySum(int arr[], int n, int sr) {

		// Your code here
		// window method
		int s = 0, e = 0, stn = 0;
		int ans_s, ans_e;
		bool found = 0;
		while (s <= e && e < n) {
			if (stn == sr) {
				ans_s = s, ans_e = e;
				found = 1;
				break;
			}
			stn += arr[e];
			if (stn > sr) {
				while (stn > sr)
					stn -= arr[s++];
			}
			if (stn == sr) {
				ans_s = s, ans_e = e;
				found = 1;
				break;
			}
			e++;
		}
		if (!found) {
			return { -1};
		}
		vector<int> ans;
		ans.push_back(ans_s + 1);
		ans.push_back(ans_e + 1);
		return ans;

	}
};