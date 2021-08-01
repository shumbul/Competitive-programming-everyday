// Link - https://www.interviewbit.com/problems/maxspprod/
// Author - Shumbul Arifa

const long long mod = 1e9 + 7;
#define ll long long
int Solution::maxSpecialProduct(vector<int> &A) {
	ll n = A.size();
	vector<ll> nll(n, 0), nlr(n, 0);
	stack<ll> st;
	// nll
	for (ll i = 0; i < n; i++) {
		while (!st.empty() && A[st.top()] <= A[i])
			st.pop();
		if (!st.empty())
			nll[i] = st.top();
		st.push(i);
	}
	while (!st.empty())
		st.pop();
	// nlr

	for (ll i = n - 1; i >= 0; i--) {
		while (!st.empty() && A[st.top()] <= A[i])
			st.pop();
		if (!st.empty())
			nlr[i] = st.top();
		st.push(i);
	}
	ll ans = 0;
	// for(int i=0;i<n;i++)
	//     cout<<nll[i]<<" "<<nlr[i]<<"\n";
	for (ll i = 0; i < n; i++)
		ans = max(ans, ((nll[i] * nlr[i])));
	return ans % (ll)mod;
}
