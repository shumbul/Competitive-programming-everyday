// Link - https://leetcode.com/contest/weekly-contest-246/problems/the-number-of-full-rounds-you-have-played/
// Author - Shumbul Arifa

class Solution {
	int solve(string startTime, string finishTime) {
		// hours
		int ans = 2 * (stoi(finishTime.substr(0, 2)) - stoi(startTime.substr(0, 2)));
		if (finishTime.substr(3, 5) != startTime.substr(3, 5))
			ans++;
		return ans;
	}
public:
	int numberOfRounds(string startTime, string finishTime) {
		// using map
		if (startTime.substr(3, 5) != "00" || startTime.substr(3, 5) != "30")
			if (startTime.substr(3, 5) < "30")
				startTime[3] = '3', startTime[4] = '0';
			else {
				startTime[3] = '0', startTime[4] = '0';
				if (startTime[0] == '2' && startTime[1] == '3')
					startTime[0] = '0', startTime[1] = '0';
			}
		if (finishTime.substr(3, 5) != "00" || finishTime.substr(3, 5) != "30")
			if (finishTime.substr(3, 5) < "30")
				finishTime[3] = '3', finishTime[4] = '0';
			else {
				finishTime[3] = '0', finishTime[4] = '0';
				if (finishTime[0] == '2' && finishTime[1] == '3')
					finishTime[0] = '0', finishTime[1] = '0';
			}

		if (finishTime.substr(0, 2) < startTime.substr(0, 2)) {
			return solve(startTime, "23:59") + solve("00:00", finishTime) + 1;
		}
		return solve(startTime, finishTime);
	}
};