// Link - https://leetcode.com/problems/gas-station/
// Author - Shumbul Arifa

// 1 -> most optimal
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int ans = -1;
		int size = gas.size();
		int total = 0;
		// check if reachable from any i to i + 1
		for (uint32_t i = 0; i < size; i++) {
			total += gas[i] - cost[i];
		}
		if (total < 0) {
			return ans;
		}
		// there must be a solution, so find starting index
		total = 0;
		ans = 0;
		for (uint32_t j = 0; j < size; j++) {
			total += gas[j] - cost[j];
			if (total < 0) {
				// ran into case where unreachable to next
				ans = j + 1; // assume next is ans
				total = 0;
			}
		}
		return ans;
	}
};

// 2
class Solution {
public:
	int canCompleteCircuit(vector<int>& A, vector<int>& B) {
		int tank = 0, ans = 0, total = 0;
		for (int i = 0; i < A.size(); i++) {
			tank += A[i] - B[i];
			if (tank < 0) {
				total += tank;
				tank = 0;
				ans = i + 1;
			}
		}
		if (total + tank < 0)
			return -1;
		return ans;

	}
};


// 3 -> least optimal
int ans = -1;
void dfs(int i, int curr, vector<int> order, const vector<int> &A, const vector<int> &B) {
	// for(auto a:order)
	//     cout<<a<<" ";
	// cout<<" --> ";
	if (order.size() == A.size()) {
		if (curr >= B[i])
			ans = i;
		return;
	}
	if (curr < B[i])
		return;
	order.push_back((i + 1) % A.size());
	dfs((i + 1) % A.size(), curr + A[(i + 1) % A.size()] - B[i], order, A, B);
}
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
	// applying dfs
	ans = -1;
	vector<int> order;
	for (int i = 0; i < A.size(); i++) {
		if (ans != -1) {
			ans = i - 1;
			break;
		}
		order = {};
		if (A[i] >= B[i])
			dfs(i, A[i], order, A, B);
	}
	return ans;
}
