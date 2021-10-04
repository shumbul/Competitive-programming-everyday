// Link - https://leetcode.com/problems/sort-integers-by-the-power-value/
// Author - Shumbul Arifa

class Solution {
	vector<pair<int, int>> v;
	int get_val(int i) {
		int ret = 0;
		while (i != 1) {
			if (i % 2)
				i = (3 * i + 1);
			else
				i = (i / 2);
			ret++;
		}
		return ret;
	}
public:
	int getKth(int lo, int hi, int k) {
		for (int i = lo; i <= hi; i++) {
			v.push_back({get_val(i), i});
		}
		sort(v.begin(), v.end());
		return v[k - 1].second;
	}
};