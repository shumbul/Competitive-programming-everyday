// Link - https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author - Shumbul Arifa

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int l, h, mid;
		l = 0, h = arr.size() - 1;
		while (l <= h) {
			mid = (h - l) / 2 + l;
			if (arr[mid] < arr[mid + 1]) {
				// everything is okay till mid+1
				l = mid + 1;
			}
			else
				h = mid - 1;
		}
		return l;
	}
};