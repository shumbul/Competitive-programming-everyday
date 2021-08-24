// Link - https://leetcode.com/problems/last-stone-weight/
// Author - Shumbul Arifa

class Solution {
public:
	int lastStoneWeight(vector<int>& s) {
		priority_queue<int> pq(s.begin(), s.end());
		while (!pq.empty()) {
			if (pq.size() < 2)
				break;
			int i1 = pq.top(); pq.pop();
			int i2 = pq.top(); pq.pop();
			if (i1 != i2)
				pq.push(i1 - i2);
		}
		if (!pq.empty())
			return pq.top();
		return 0;
	}
};