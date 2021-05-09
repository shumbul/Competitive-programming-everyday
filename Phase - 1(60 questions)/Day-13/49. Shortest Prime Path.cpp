// Link - https://practice.geeksforgeeks.org/problems/2b9978653b4d905d12c04387a60e16464ef40733/0/
// Author - Shumbul Arifa

class Solution {
	vector<int> ar[10001];
	bool vis[10001];
	int dist[10001];
	vector<int> primes;
	bool prime[10001];
	void sieve() {
		memset(prime, true, sizeof prime);
		int n = sizeof(prime) - 1;
		for (int p = 2; p * p <= n ; p++) {
			if (prime[p] == true) {
				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}
		for (int p = 1000; p <= 9999; p++)
			if (prime[p])
				primes.push_back(p);
	}
	bool isprime(int n) {
		if (prime[n])
			return true;
		return false;
	}
	bool isValid(int A, int B) {
		int a = A, b = B;
		int cnt = 0;
		while (a > 0 && cnt < 2) {
			if (a % 10 != b % 10)
				cnt++;
			a /= 10, b /= 10;
		}
		if (cnt == 1)
			return true;
		return false;
	}
	void buildGraph() {
		for (int i = 0; i < primes.size(); i++) {
			for (int j = i + 1; j < primes.size(); j++) {
				int a = primes[i], b = primes[j];
				if (isValid(a, b)) {
					ar[a].push_back(b);
					ar[b].push_back(a);
					// cout<<a<<' '<<b<<"\n";
				}
			}
		}
	}
	void bfs(int src) {
		queue<int> q;
		q.push(src);
		dist[src] = 0, vis[src] = 1;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int child : ar[curr]) {
				if (vis[child] == 0) {
					vis[child] = 1;
					dist[child] = dist[curr] + 1;
					q.push(child);
				}
			}
		}
	}

public:
	int solve(int Num1, int Num2)
	{
		//code here
		for (int i = 1000; i <= 9999; i++)
			dist[i] = -1, vis[i] = 0;
		sieve();
		buildGraph();

		// BFS on prime numbers
		bfs(Num1);
		return dist[Num2];
	}
};