// Link - https://practice.geeksforgeeks.org/problems/relative-sorting4323/1#
// Author - Shumbul Arifa

class Solution {
public:
	// A1[] : the input array-1
	// N : size of the array A1[]
	// A2[] : the input array-2
	// M : size of the array A2[]

	//Function to sort an array according to the other array.
	vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
	{
		//Your code here
		unordered_map<int, int> mp;
		vector<int> ans, ans2;
		int k = 1;  // sequence
		for (int a : A1) {
			mp[a]++;
		}
		for (int i = 0; i < M; i++) {
			if (mp.find(A2[i]) != mp.end()) {
				for (int j = 0; j < mp[A2[i]]; j++) {
					ans.push_back(A2[i]);
				}
				mp.erase(A2[i]);
			}
		}
		for (auto a : mp) {
			for (int j = 0; j < a.second; j++) {
				ans2.push_back(a.first);
			}
		}
		sort(ans2.begin(), ans2.end());
		for (int a : ans2) {
			ans.push_back(a);
		}
		return ans;
	}
};