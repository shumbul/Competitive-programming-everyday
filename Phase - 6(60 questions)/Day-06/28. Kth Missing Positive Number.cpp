// Link - https://leetcode.com/problems/kth-missing-positive-number/
// Author - Shumbul Arifa

class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int l = 0, h = arr.size();
		int mid;
		while (l < h) {
			mid = (h - l) / 2 + l;
			if (arr[mid] - mid - 1 < k)
				l = mid + 1;
			else
				h = mid;
		}
		return l + k;
	}
};