// Link -  https://leetcode.com/problems/find-center-of-star-graph
// Author - Shumbul Arifa

class Solution {
public:
	int findCenter(vector<vector<int>>& edges) {
		set<int> st;
		vector<int> v1 = edges[0], v2 = edges[1];
		for (int i = 0; i < 2; i++) {
			st.insert(v1[i]);
		}
		for (int i = 0; i < 2; i++) {
			if (st.find(v2[i]) != st.end())
				return v2[i];
		}
		return -1;
	}
};

// Method -2
class Solution {
public:
	int findCenter(vector<vector<int>>& e) {
		return e[0][0] == e[1][0] ? e[0][0] : (e[0][0] == e[1][1] ? e[0][0] : e[0][1]);
	}
};