// Link - https://www.pramp.com/challenge/3QnxW6xoPLTNl5jX5Lg1
// Author - Shumbul Arifa

vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur)
{
	// your code goes here
	// 1. removing all slots with duration < dur
	vector<vector<int>> A;
	for (auto s : slotsA) {
		if (s[1] - s[0] >= dur)
			A.push_back(s);
	}
	vector<vector<int>> B;
	for (auto s : slotsB) {
		if (s[1] - s[0] >= dur)
			B.push_back(s);
	}
	// 2. traversing A & B to find a slot
	// 1 ≤ slotsA.length ≤ 100
	// 1 ≤ slotsB.length ≤ 100

	vector<int> ans;
	int i = 0, j = 0;
	while (i < A.size() && j < B.size()) {
		int A1 = A[i][0], A2 = A[i][1];
		int B1 = B[j][0], B2 = B[j][1];
		if (min(A2, B2) - max(A1, B1) >= dur) {
			ans.push_back(max(A1, B1));
			ans.push_back(max(A1, B1) + dur);
			return ans;
		}
		if (A2 < B2)
			i++;
		else
			j++;
	}
	return ans;
}

/*
input:  slotsA = [[10, 50], [60, 120], [140, 210]]
        slotsB = [[0, 15], [60, 70]]
        dur = 8
output: [60, 68]

input:  slotsA = [[10, 50], [60, 120], [140, 210]]
        slotsB = [[0, 15], [60, 70]]
        dur = 12
output: [] # since there is no common slot whose duration is 12
*/