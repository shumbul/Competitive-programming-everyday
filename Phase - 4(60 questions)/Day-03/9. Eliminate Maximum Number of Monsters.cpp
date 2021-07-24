// Link - https://leetcode.com/contest/weekly-contest-248/problems/eliminate-maximum-number-of-monsters/
// Author - Shumbul Arifa

class Solution {
public:
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
		int i, n = dist.size();
		vector<double> time;
		for (i = 0; i < n; i++) {
			time.push_back((double)dist[i] / (double)speed[i]);
		}
		sort(time.begin(), time.end());
		int t = 0;
		int ans = 0;
		for (auto a : time) {
			cout << a << " ";
			if (a <= t) {
				break;
			}
			else {
				t++;
				ans++;
			}
		}
		return ans;
	}
};