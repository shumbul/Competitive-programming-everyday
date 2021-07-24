// Link - https://www.interviewbit.com/old/problems/sliding-window-maximum/
// Author - Shumbul Arifa


vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
	vector<int> ans;
	if (B == 0)
		return ans;
	if (B == 1) {
		ans = A;
		return ans;
	}
	if (B >= A.size()) {
		ans.push_back(*max_element(A.begin(), A.end()));
		return ans;
	}

	int i = 0, j = 0;
	// dequeue to get a minimal and sorted data structure to store values
	deque<int> s;
	while (j < A.size()) {
		// for(auto p:s){
		//     cout<<p<< " -> ";
		// }
		// cout<<"\tnextline\t";
		if (j - i + 1 < B) {
			if (s.size() == 0)
				s.push_back(j);
			else {
				while (s.size() > 0 && A[s[s.size() - 1]] <= A[j])
					s.pop_back();
				s.push_back(j);
			}
			j++;
			continue;
		}
		// include j'th value from array
		while (s.size() > 0 && A[s[s.size() - 1]] <= A[j])
			s.pop_back();
		s.push_back(j);
		// window size is minimal
		ans.push_back(A[s[0]]);
		// erase ith index if that still exists
		auto it = find(s.begin(), s.end(), i);
		if (it != s.end())
			s.erase(it);
		i++, j++;
	}
	return ans;
}

// EDITORIAL SOLUTION

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
	deque< pair<int, int> > window;
	for (int i = 0; i < A.size(); i++) {
		//remove smaller elements from back
		while (!window.empty() && window.back().first <= A[i])  window.pop_back();
		window.push_back(make_pair(A[i], i));

		//remove those which do not belong to this window
		while (window.front().second <= i - B)
			window.pop_front();
		if (i >= B - 1)
			cout << (window.front().first) << ' ';
	}
	return {};
}