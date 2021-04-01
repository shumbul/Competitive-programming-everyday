// Link -
// Author - Shumbul Arifa

class Solution {
	map<int, int> mp;
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		// sort based on their frequencies
		for (auto num : nums) {
			mp[num]++;
		}
		vector<pair<int, int>> q;
		for (auto a : mp) {
			q.push_back(make_pair(a.first, a.second));
		}
		sort(q.begin(), q.end(), [](const pair<int, int> &s1, const pair<int, int> &s2) {
			return s1.second > s2.second;
		});
		q.resize(k);
		vector<int> v;
		for (int i = 0; i < k; i++)
			v.push_back(q[i].first);
		return v;
	}
};