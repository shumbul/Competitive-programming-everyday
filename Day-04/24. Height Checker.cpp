// Link - https://leetcode.com/problems/height-checker/
// Author - Shumbul Arifa

// Brute Force
class Solution {
public:
	int heightChecker(vector<int>& heights) {
		auto a = heights;
		sort(a.begin(), a.end());
		int n = a.size(), cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != heights[i])
				cnt++;
		}
		return cnt;
	}
};

// when we consider the constraints:
int heightChecker(vector<int>& heights) {
	int mismatch = 0; //count the number of mismatches
	vector<int> count(101, 0); // store the count of heights

	for (int i = 0; i < heights.size(); i++) count[heights[i]]++;

	int i = 1, j = 0;
	while (i < 101) {
		// check value of count
		if (count[i] == 0) {
			i++;
		}
		else {
			// compare the index of count with value of height
			if (i != heights[j]) mismatch++;
			j++; count[i]--;
		}
	}

	return mismatch;
}