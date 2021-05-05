// Link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Author - Shumbul Arifa

class Solution
{
	vector<bool> vis;
	vector<int> ans;
	void dfs(int n, vector<int> adj[]) {
		vis[n] = 1;
		ans.push_back(n);
		for (int i : adj[n]) {
			if (!vis[i])
				dfs(i, adj);
		}
	}
public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
		// Code here
		vis.clear();
		ans.clear();
		vis.resize(V);
		dfs(0, adj);
		return ans;
	}
};