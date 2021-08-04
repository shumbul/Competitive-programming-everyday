// Link - https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#
// Author - Shumbul Arifa

class Solution
{
public:
	//Function to return the minimum cost of connecting the ropes.
	long long minCost(long long ar[], long long n) {
		// Your code here
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		long long ans = 0, i, t1, t2;
		for (i = 0; i < n; i++) pq.push(ar[i]);
		while (pq.size() > 1) {
			t1 = pq.top(), pq.pop();
			t2 = pq.top(), pq.pop();
			ans += t1 + t2;
			pq.push(t1 + t2);
		}
		return ans;
	}
};