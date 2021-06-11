// Link - https://www.hackerearth.com/challenges/competitive/nokia-collegiate-code-warriors-hunt-2021/algorithm/find-it-5-16e2e6bd/
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int solve (int N, vector<int> A, int Q, vector<vector<int> > ops) {
	// Write your code here
	// brute force
	for (int i = 0; i < Q; i++) {
		if (ops[i][0] == 1) {
			for (int j = ops[i][1] - 1; j < ops[i][2]; j++)
				A[j] += ops[i][3];
		}
		else if (ops[i][0] == 2) {
			for (int j = ops[i][1] - 1; j < ops[i][2]; j++)
				A[j] -= ops[i][3];
		}
	}
	long long int ans = 0;
	// this could be optimized!
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				ans = (ans + ((A[i] + A[j]) % mod * (A[j] + A[k]) % mod) % mod) % mod;
			}
		}
	}
	return ans % mod;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++)
	{
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i_A = 0; i_A < N; i_A++)
		{
			cin >> A[i_A];
		}
		int Q;
		cin >> Q;
		vector<vector<int> > operations(Q, vector<int>(4));
		for (int i_operations = 0; i_operations < Q; i_operations++)
		{
			for (int j_operations = 0; j_operations < 4; j_operations++)
			{
				cin >> operations[i_operations][j_operations];
			}
		}

		int out_;
		out_ = solve(N, A, Q, operations);
		cout << out_;
		cout << "\n";
	}
}