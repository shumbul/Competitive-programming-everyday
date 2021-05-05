// Link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Author - Shumbul Arifa

class Solution
{
public:
	//Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
		// Code here
		queue<int> q;
		vector<int> ans;
		bool vis[V];
		q.push(0);
		while (!q.empty()) {
			int curr = q.front();
			ans.push_back(curr);
			vis[curr] = 1;
			q.pop();
			for (int ch : adj[curr]) {
				if (!vis[ch]) {
					q.push(ch);
					vis[ch] = 1;
				}
			}
		}
		return ans;
	}
};