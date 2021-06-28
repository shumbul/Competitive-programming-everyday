// Link - https://www.interviewbit.com/old/problems/distinct-numbers-in-window/
// Author - Shumbul Arifa

vector<int> Solution::dNums(vector<int> &A, int B) {
	vector<int> ans;
	int n = A.size();
	if (B == 0)
		return ans;
	if (B == 1 || n == 1) {
		ans.resize(n, 1);
		return ans;
	}
	map<int, int> mp;
	for (int i = 0; i < B; i++) {
		mp[A[i]]++;
	}
	for (int i = B; i < n; i++) {
		ans.push_back(mp.size());
		mp[A[i]]++;
		mp[A[i - B]]--;
		if (mp[A[i - B]] == 0)
			mp.erase(A[i - B]);
	}
	ans.push_back(mp.size());
	mp.clear();
	return ans;
}

/* EDITORIAL

vector<int> Solution::dNums(vector<int> &A, int B) {
    assert(B<=A.size());
    int n=A.size();
    vector<int> ret;
    unordered_map <int, int> m;
    for(int i=0; i<n; i++){
        //increase key
        m[A[i]]++;
        if(i-B+1>=0){

            //decrease key
            ret.push_back(m.size());
            m[A[i-B+1]]--;

            //remove if count becomes 0
            if(m[A[i-B+1]]==0)m.erase(A[i-B+1]);
        }
    }
    return ret;
}

*/