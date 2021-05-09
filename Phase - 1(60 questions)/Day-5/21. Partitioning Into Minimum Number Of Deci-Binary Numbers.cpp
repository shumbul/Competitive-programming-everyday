// Link - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Author - Shumbul Arifa

class Solution {
public:
	int minPartitions(string n) {
		// find the pattern taking values from 0 to 110
		return *max_element(n.begin(), n.end()) - '0';
	}
};