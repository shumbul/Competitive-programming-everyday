// Link - https://leetcode.com/problems/maximum-units-on-a-truck/
// Author - Shumbul Arifa

class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int t) {
		// greedy
		auto b = boxTypes;
		int ans = 0;
		sort(b.begin(), b.end(), [](const auto & s1, const auto & s2) {
			if (s1[1] != s2[1])
				return s1[1] > s2[1];
			return s1[0] < s1[0];
		});
		// for(auto a:b){
		//     for(auto c:a){
		//         cout<<c<<" ";
		//     }
		//     cout<<"\n";
		// }
		for (auto a : b) {
			int q = min(t, a[0]);
			ans += q * a[1];
			t -= q;
			if (!t)
				break;
		}
		return ans;
	}
};