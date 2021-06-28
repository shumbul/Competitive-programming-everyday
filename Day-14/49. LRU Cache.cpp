// Link - interviewbit.com/old/problems/lru-cache/
// Author - Shumbul Arifa

vector<int> v;
map<int, int> mp;
set<int> st;
int n;

LRUCache::LRUCache(int cap) {
	v.clear();
	mp.clear();
	st.clear();
	assert(cap != 0);
	n = cap;
}

int LRUCache::get(int key) {
	// cout<<"Get "<<key<<"\n";
	// for(auto a:st)
	//     cout<<a<<" ";
	// cout<<"\n";
	// for(auto a:v)
	//     cout<<a<<" ";
	// cout<<"\n";
	if (st.find(key) == st.end())
		return -1;
	auto it = find(v.begin(), v.end(), key);
	v.erase(it);
	v.push_back(key);
	// cout<<"found\n";
	// for(auto a:st)
	//     cout<<a<<" ";
	// cout<<"\n";
	// for(auto a:v)
	//     cout<<a<<" ";
	// cout<<"\n\n";
	return mp[key];
}

void LRUCache::set(int key, int value) {
	if (st.find(key) != st.end()) {
		// it is used
		auto it = find(v.begin(), v.end(), key);
		v.erase(it);
		v.push_back(key);
		mp[key] = value;
		return;
	}
	// erase
	if (v.size() < n) {
		st.insert(key);
		v.push_back(key);
		mp[key] = value;
		return;
	}
	st.erase(v[0]);
	mp.erase(v[0]);
	st.insert(key);
	v.erase(v.begin());
	v.push_back(key);
	mp[key] = value;
}

