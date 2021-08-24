// Link - https://leetcode.com/problems/baseball-game/
// Author - Shumbul Arifa

class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> st;
		for (auto a : ops) {
			if (a == "C") {
				st.pop_back();
			}
			else if (a == "D") {
				st.push_back(2 * st[st.size() - 1]);
			}
			else if (a == "+") {
				int i1 = st[st.size() - 1];
				int i2 = st[st.size() - 2];
				st.push_back(i1 + i2);
			}
			else {
				st.push_back(stoi(a));
			}
		}
		int ans = accumulate(st.begin(), st.end(), 0);
		return ans;
	}
}; https: //leetcode.com/problems/baseball-game/