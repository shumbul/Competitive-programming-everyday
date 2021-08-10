// Link - https://leetcode.com/problems/remove-stones-to-minimize-the-total/
// Author - Shumbul Arifa

class Solution {
public:
	int minStoneSum(vector<int>& piles, int k) {
		priority_queue<int> pq(piles.begin(), piles.end());
		while (k--) {
			int top = pq.top();
			// cout<<ceil(top/2)<<" ";
			pq.pop();
			pq.push(top - top / 2);
		}
		int ans = 0;
		while (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
		return ans;
	}
};