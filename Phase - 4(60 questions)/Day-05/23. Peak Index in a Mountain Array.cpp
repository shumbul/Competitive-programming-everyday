// Link - https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author - Shumbul Arifa

// 1
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		return max_element(arr.begin(), arr.end()) - arr.begin();
	}
};

// 2
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int l, h, mid, ans = -1;
		l = 0, h = arr.size() - 1;
		while (l <= h) {
			mid = (h - l) / 2 + l;
			if (arr[mid] >= arr[mid + 1]) {
				ans = mid;
				h = mid - 1;
			}
			else
				l = mid + 1;
		}
		return ans;
	}
};

// 3
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int l, h, mid;
		l = 0, h = arr.size() - 1;
		while (l <= h) {
			mid = (h - l) / 2 + l;
			if (arr[mid] < arr[mid + 1]) {
				l = mid + 1;
			}
			else
				h = mid - 1;
		}
		return l;
	}
};