// Link - https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Author - Shumbul Arifa

class Solution {
	int mod = 1000000007;
public:
	int maxArea(int h, int w, vector<int>& HC, vector<int>& VC) {
		auto hc = HC, vc = VC;
		if (find(hc.begin(), hc.end(), 0) == hc.end())
			hc.insert(hc.begin(), 0);
		if (find(vc.begin(), vc.end(), 0) == vc.end())
			vc.insert(vc.begin(), 0);
		if (find(hc.begin(), hc.end(), h) == hc.end())
			hc.push_back(h);
		if (find(vc.begin(), vc.end(), w) == vc.end())
			vc.push_back(w);

		sort(hc.begin(), hc.end());
		sort(vc.begin(), vc.end());
		long long int max_diff_h = 0, max_diff_v = 0;
		for (unsigned int i = 1; i < hc.size(); i++)
			if (max_diff_h < hc[i] - hc[i - 1])
				max_diff_h = hc[i] - hc[i - 1];
		for (unsigned int i = 1; i < vc.size(); i++)
			if (max_diff_v < vc[i] - vc[i - 1])
				max_diff_v = vc[i] - vc[i - 1];
		int ans = (int)(max_diff_h % mod * max_diff_v % mod);
		return ans;
	}
};